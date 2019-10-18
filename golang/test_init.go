package main

import (
	"fmt"
)

var global_num int = 10
var global_slice []int = []int{1, 2, 3}

var c = func() int {
	return 3
}()

func main() {
	fmt.Println("hello,world", global_num, global_slice, c)
}
