package main

import (
	"fmt"
	"reflect"
	"unsafe"
)

func foo(a *[]byte) {
	*a = []byte{'1', '3', '5'}
}
func main() {

	// ori := make([]byte, 0)
	var ori []byte
	foo(&ori)
	fmt.Println(ori)

	fmt.Println("======================")
	slice1 := make([]int, 1)
	fmt.Println(unsafe.Sizeof(slice1))
	fmt.Println(cap(slice1), len(slice1), unsafe.Pointer(&slice1))
	d := (*reflect.SliceHeader)(unsafe.Pointer(&slice1))
	fmt.Println(*d)

	slice1 = append(slice1, 1)
	slice1 = append(slice1, 2)
	slice1 = append(slice1, 1)
	fmt.Println(cap(slice1), len(slice1), unsafe.Pointer(&slice1))
	fmt.Println(slice1)
	d = (*reflect.SliceHeader)(unsafe.Pointer(&slice1))
	fmt.Println(*d)

	slince2 := make([]int, 5, 10)
	fmt.Println(cap(slince2), len(slince2))
}
