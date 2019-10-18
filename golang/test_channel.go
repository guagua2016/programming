package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	go func() {
		tick := time.Tick(1 * time.Second)
		for {
			select {
			case <-time.After(5 * time.Second):
				fmt.Println("time out")
			case <-tick:
				fmt.Println("time tick 1s")
			default:
				fmt.Println("default")
			}
		}
	}()
	<-(chan struct{})(nil)
}
