package main

import (
	"fmt"
)

const goroutineNum = 7
const maxVal = 100

func main() {

	chans := make([]chan int, goroutineNum)
	for i := 0; i < goroutineNum; i++ {
		chans[i] = make(chan int, 1)
	}

	// exitChan
	exitChan := make(chan int)

	cur := 1

	for i := 0; i < goroutineNum; i++ {
		go func(i int) {
			for {
				<-chans[i]
				if cur > maxVal {
					exitChan <- 1
					break
				}
				fmt.Printf("gountine = %d,cur = %d\n", i, cur)
				cur = cur + 1
				next := i + 1
				if next >= goroutineNum {
					next = 0
				}
				chans[next] <- 1
			}
		}(i)
	}

	chans[0] <- 1 // start

	select {
	case <-exitChan:
		fmt.Println("end")
	}

}
