package main

import (
	// "fmt"
	"time"
)

func main() {
	for i := 0; i < 10; i++ {
		go func(ii int) {
			for {
				//fmt.Printf("Hello %d\n", ii)
			}
		}(i)
	}

	time.Sleep(time.Second)
}
