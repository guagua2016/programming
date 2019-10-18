package main

import (
	"fmt"
	"math"
	"runtime"
	"sync"
)

func count() {
	x := 0
	for i := 0; i < math.MaxUint32; i++ {
		x += i
	}
	fmt.Println(x)
}

func test(n int) {
	for i := 0; i < n; i++ {
		count()
	}
}

func test2(n int) {
	var wg sync.WaitGroup
	for i := 0; i < n; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			count()
		}()
	}
	wg.Wait()
}

func main() {

	runtime.GOMAXPROCS(8)

	test2(4)
	// fmt.Println(4)
}
