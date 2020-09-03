package util

import (
	"context"
	"os"
	"os/signal"
	"sync"
	"syscall"
	"time"

	"github.com/Shopify/sarama"
	"log"
)

// Consumer represents a Sarama consumer group consumer
type Consumer struct {
	ready    chan bool
	dataChan chan *sarama.ConsumerMessage
}

// Setup is run at the beginning of a new session, before ConsumeClaim
func (c *Consumer) Setup(sarama.ConsumerGroupSession) error {
	// Mark the consumer as ready
	close(c.ready)
	return nil
}

// Cleanup is run at the end of a session, once all ConsumeClaim goroutines have exited
func (c *Consumer) Cleanup(sarama.ConsumerGroupSession) error {
	return nil
}

// ConsumeClaim must start a consumer loop of ConsumerGroupClaim's Messages().
func (c *Consumer) ConsumeClaim(session sarama.ConsumerGroupSession, claim sarama.ConsumerGroupClaim) error {
	// NOTE:
	// Do not move the code below to a goroutine.
	// The `ConsumeClaim` itself is called within a goroutine, see:
	// https://github.com/Shopify/sarama/blob/master/consumer_group.go#L27-L29

	for message := range claim.Messages() {
		log.Printf("Message claimed: timestamp = %+v, topic = %+v, partition = %+v", message.Timestamp, message.Topic, message.Partition)
		session.MarkMessage(message, "")
		c.dataChan <- message
	}
	return nil
}

// ConsumeClaim must start a consumer loop of ConsumerGroupClaim's Messages().
func (c *Consumer) ReadOne() *sarama.ConsumerMessage {
	select {
	case m, ok := <-c.dataChan:
		if ok {
			return m
		} else {
			log.Errorf("Kafka Readone error %+v", ok)
			return nil
		}
	}
}

func NewKafkaConsumer(brokers []string, group string, topics []string) *Consumer {
	cl := Consumer{}
	cl.ready = make(chan bool)
	cl.dataChan = make(chan *sarama.ConsumerMessage, 1)
	// topicList := strings.Split(topic, ",")
	go kafkaConsumerGroupConfig(brokers, topics, group, &cl)
	time.Sleep(1 * time.Second)
	return &cl
}

func kafkaConsumerGroupConfig(brokers, topics []string, group string, consumer *Consumer) {
	log.Printf("kafka config %+v,%+v,%+v", brokers, topics, group)
	config := sarama.NewConfig()
	config.Version = sarama.V1_1_1_0 // 指定协议版本号
	config.ClientID = group          // 消费者ID，从管理平台中生成
	config.Consumer.Return.Errors = true
	config.Consumer.Fetch.Default = 524288                   // 单次消费拉取请求中，单个分区最大返回消息大小。一次拉取请求可能返回多个分区的数据，这里限定单个分区的最大数据大小
	config.Consumer.Fetch.Max = 1048576                      // 单次消费拉取请求中，单个分区最大返回消息大小。一次拉取请求可能返回多个分区的数据，这里限定单个分区的最大数据大小
	config.Consumer.MaxWaitTime = 1000 * time.Millisecond    // 单次消费拉取请求最长等待时间。最长等待时间仅在没有最新数据时才会等待。此值应当设置较大点，减少空请求对服务端QPS的消耗。
	config.Consumer.Offsets.CommitInterval = 3 * time.Second // 定时多久一次提交消费进度
	sarama.MaxResponseSize = 1048576                         // 单次消费拉取请求，最大拉取包大小。
	// 根据经验，这里设置100K-1M比较合适。设置太大，消费吞吐力上不去（从服务端拉数据和业务处理数据差不多变串行了），设置太小，则sdk会发送大量请求到服务端，kafka服务端TPS很容易触达上限，导致整体吞吐能力下降
	// 不论值大与小，kafka服务端如果有数据返回，一定会返回一个完整的数据包。（比如一条消息大小为1K，设置max为900，则也会返回这一条1K大消息的完整包）
	config.Metadata.Full = false                            //禁止拉取所有元数据
	config.Metadata.Retry.Max = 1                           //元数据更新重次次数
	config.Metadata.Retry.Backoff = 1000 * time.Millisecond //元数据更新等待时间

	config.Consumer.Offsets.Initial = sarama.OffsetOldest

	ctx, cancel := context.WithCancel(context.Background())
	client, err := sarama.NewConsumerGroup(brokers, group, config)
	if err != nil {
		log.Errorf("error:%+v", err)
		panic(err)
	}
	wg := &sync.WaitGroup{}
	wg.Add(1)
	go func() {
		defer wg.Done()
		for {
			// `Consume` should be called inside an infinite loop, when a
			// server-side rebalance happens, the consumer session will need to be
			// recreated to get the new claims

			if err := client.Consume(ctx, topics, consumer); err != nil {
				time.Sleep(time.Second * 2)
				log.Errorf("error:%+v", err)
				// panic(err)
			}
			// check if context was cancelled, signaling that the consumer should stop
			if ctx.Err() != nil {
				return
			}
			consumer.ready = make(chan bool)
		}
	}()
	<-consumer.ready // Await till the consumer has been set up
	log.Debug("Sarama consumer up and running!...")
	sigterm := make(chan os.Signal, 1)
	signal.Notify(sigterm, syscall.SIGINT, syscall.SIGTERM)
	select {
	case <-ctx.Done():
		log.Debug("terminating: context cancelled")
	case <-sigterm:
		log.Debug("terminating: via signal")
	}
	cancel()
	wg.Wait()
	if err = client.Close(); err != nil {
		log.Errorf("Error closing client: %v", err)
	}
}

// NewCMQKafkaProducer create a sarama.SyncProducer
func NewCMQKafkaProducer(brokers []string, clientID string) sarama.SyncProducer {
	log.Printf("brokers %+v", brokers)
	config := sarama.NewConfig()
	config.Producer.RequiredAcks = sarama.WaitForAll
	config.Producer.Partitioner = sarama.NewRandomPartitioner
	config.Producer.Return.Successes = true
	config.Producer.Timeout = 5 * time.Second

	config.ClientID = clientID                // 生产者ID，从管理平台中生成
	config.Version = sarama.V1_1_1_0          // 指定协议版本号
	config.Producer.Timeout = 3 * time.Second // 请求在服务端最长请求处理时间
	config.Producer.MaxMessageBytes = 131072
	config.Producer.Compression = sarama.CompressionGZIP
	config.Metadata.Full = false                            //禁止拉取所有元数据
	config.Metadata.Retry.Max = 1                           //元数据更新重次次数
	config.Metadata.Retry.Backoff = 1000 * time.Millisecond //元数据更新等待时间

	pro, err := sarama.NewSyncProducer(brokers, config)
	if err != nil {
		log.Errorf("kafka producer create error: %+v,%+v", err, config)
		panic(err)
	} else {
		log.Printf("kafka producer create success: %+v", config)
	}
	return pro
}
