package main

import (
	"fmt"
	"time"
)

var chan1 chan int
var chan2 chan int

func foo1() {
	for i := 0; i < 10; i++ {
		chan1 <- 2*i + 1
		fmt.Println(<-chan2)
	}
}

func foo2() {
	for i := 1; i <= 10; i++ {
		fmt.Println(<-chan1)
		chan2 <- 2 * i
	}
}

func main() {
	chan1 = make(chan int)
	chan2 = make(chan int)
	go foo1()
	go foo2()

	time.Sleep(3 * time.Second)
}
