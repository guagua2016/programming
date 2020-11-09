package main

import (
	"fmt"
	// "sync"
	"time"
)

func produce1(queue chan int, exitChan chan int) {
	for i := 1; i < 100; i += 2 {
		queue <- i
	}
	fmt.Println("producer1 end")
	exitChan <- 1
}

func produce2(queue chan int, exitChan chan int) {
	for i := 0; i < 100; i += 2 {
		queue <- i
	}
	fmt.Println("producer2 end")
	exitChan <- 1
}

func consume1(queue chan int, exitChan chan int) {
	time.Sleep(3 * time.Second)
	for v := range queue {
		fmt.Println(v)
	}
	fmt.Println("consume end")
	exitChan <- 1
}

func consume2(queue chan int, exitChan chan int) {
	time.Sleep(3 * time.Second)
	for v := range queue {
		fmt.Println(v)
	}
	fmt.Println("consume end")
	exitChan <- 1
}

const producerNum = 5
const consumerNum = 4

func main() {

	queue := make(chan int, 2) // buffer size

	exitChans := make([]chan int, 4)
	for i := 0; i < 4; i++ {
		exitChans[i] = make(chan int, 1)
	}

	go produce1(queue, exitChans[0])
	go produce2(queue, exitChans[1])
	go consume1(queue, exitChans[2])
	go consume2(queue, exitChans[3])

	<-exitChans[0]
	<-exitChans[1]
	close(queue)
	<-exitChans[2]
	<-exitChans[3]
	// <-exitChans[2]
}
