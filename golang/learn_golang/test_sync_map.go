package main

import (
	"fmt"
	"sync"
)

func main() {

	var sMap sync.Map

	vv, ok := sMap.LoadOrStore("111", "aaa")
	fmt.Println(vv, ok)

	vv, ok = sMap.LoadOrStore(111, "aaa")
	fmt.Println(vv, ok)

	vv, ok = sMap.LoadOrStore(111, "bbb")
	fmt.Println(vv, ok)

	sMap.Store(111, "bbb")

	sMap.Range(func(k, v interface{}) bool {
		fmt.Println(k, v)
		return true
	})

	// m := make(map[int]int, 1)

	// go func() {
	// 	for {
	// 		_ = m[1]
	// 	}
	// }()

	// go func() {
	// 	for {
	// 		m[2] = 2
	// 	}
	// }()

	// select {}
}
