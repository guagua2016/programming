package main

import (
	// "fmt"
	// "runtime"
	"sync"
	"time"
)

func main() {
	var wg sync.WaitGroup
	wg.Add(10)

	for i := 0; i < 10; i++ {
		go work(&wg)
	}

	wg.Wait()

	time.Sleep(3 * time.Second)
}

func work(wg *sync.WaitGroup) {
	time.Sleep(time.Second)

	var counter int
	for i := 0; i < 1e11; i++ {
		_ = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
		//fmt.Println(s)
		counter++
	}

	wg.Done()
}
