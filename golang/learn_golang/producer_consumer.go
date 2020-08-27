package main

import (
	"fmt"
	"sync"
	"time"
)

var queue chan byte

func produce(wg *sync.WaitGroup, n int, b byte) {
	defer wg.Done()
	for i := 0; i < n; i++ {
		queue <- b
		if len(queue) == cap(queue) {
			fmt.Println("the queue is full", i)
		}
	}
}

func consume(wg *sync.WaitGroup) {
	defer wg.Done()
	for {
		var c byte
		select {
		case c = <-queue:
			fmt.Println(string(c))
		case <-time.After(3 * time.Second):
			fmt.Println("No data")
			return
		}
	}
}

func main() {
	queue = make(chan byte, 2)
	var wg sync.WaitGroup
	wg.Add(1)
	go produce(&wg, 10, 'c')
	wg.Add(1)
	go produce(&wg, 10, 'x')
	wg.Add(1)
	go consume(&wg)

	wg.Wait()
}
