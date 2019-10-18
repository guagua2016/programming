package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	fmt.Println(time.Now())

	var a time.Duration
	if a == 0 {
		fmt.Println("a == 0")
	}
	fmt.Println("default value:", a)

	//strimg to time
	t, err := time.Parse("2006-01-02 15:04:05", "2018-04-23 12:24:51")
	if err == nil {
		fmt.Println(t)
	}

	t, err = time.ParseInLocation("2006-01-02 15:04:05", "2018-04-23 12:24:51", time.Local)
	if err == nil {
		fmt.Println(t)
	}

	//get time and conver to string
	fmt.Println(time.Now().Format("2006-01-02 15:04:05"))

	//time type to unix stamp
	fmt.Println(t.Unix())

	time.Sleep(3 * time.Second)
	time.Sleep(time.Second * 1)
	time.Sleep(time.Duration(1) * time.Second)
	// time.Sleep(1 * time.Hour)

	tp, err := time.ParseDuration("1.5s")
	if err == nil {
		fmt.Println(tp)
	}

	//compare time
	fmt.Println(time.Now().After(t))

	var wg sync.WaitGroup
	wg.Add(2)
	//NewTimer 创建一个 Timer，它会在最少过去时间段 d 后到期，向其自身的 C 字段发送当时的时间
	timer1 := time.NewTimer(2 * time.Second)

	//NewTicker 返回一个新的 Ticker，该 Ticker 包含一个通道字段，并会每隔时间段 d 就向该通道发送当时的时间。它会调
	//整时间间隔或者丢弃 tick 信息以适应反应慢的接收者。如果d <= 0会触发panic。关闭该 Ticker 可
	//以释放相关资源。
	ticker1 := time.NewTicker(2 * time.Second)

	go func(t *time.Ticker) {
		defer wg.Done()
		for {
			<-t.C
			fmt.Println("get ticker1", time.Now().Format("2006-01-02 15:04:05"))
		}
	}(ticker1)

	go func(t *time.Timer) {
		defer wg.Done()
		for {
			<-t.C
			fmt.Println("get timer", time.Now().Format("2006-01-02 15:04:05"))
			//Reset 使 t 重新开始计时，（本方法返回后再）等待时间段 d 过去后到期。如果调用时t
			//还在等待中会返回真；如果 t已经到期或者被停止了会返回假。
			t.Reset(2 * time.Second)
		}
	}(timer1)

	wg.Wait()
}
