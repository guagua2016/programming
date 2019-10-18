package main

import (
	"fmt"
	"unsafe"
)

func main() {

	var i32 int32
	i32 = 10

	fmt.Println(unsafe.Sizeof(i32))

	a := struct{}{}
	b := struct{}{}
	fmt.Println(a == b)
	fmt.Printf("%p,%p\n", &a, &b)
}
