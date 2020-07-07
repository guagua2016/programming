package main

import (
	"runtime"
	"sync"
	"time"
)

func main() {
	var wg sync.WaitGroup
	runtime.GOMAXPROCS(8)
	wg.Add(100)
	for i := 0; i < 100; i++ {
		go work(&wg)
	}
	wg.Wait()
	// Wait to see the global run queue deplete.
	time.Sleep(3 * time.Second)
}
func work(wg *sync.WaitGroup) {
	time.Sleep(time.Second)
	var counter int
	for i := 0; i < 1e10; i++ {
		counter++
	}
	wg.Done()
}
