package main

import (
	"fmt"
	"sync"
)

func main() {
	var m sync.Mutex
	fmt.Printf("%#v\n", m)
}
