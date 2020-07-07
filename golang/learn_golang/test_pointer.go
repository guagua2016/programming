package main

import (
	"fmt"
	"unsafe"
)

func main() {
	var ii [4]int = [4]int{11, 22, 33, 44}
	px := &ii[0]
	fmt.Println(&ii[0], px, *px)

	//compile error
	//pf32 := (*float32)(px)

	//compile error
	// px = px + 8
	// px++

	var pointer1 unsafe.Pointer = unsafe.Pointer(px)
	var pf32 *float32 = (*float32)(pointer1)

	var p2 uintptr = uintptr(pointer1)
	print(p2)
	p2 = p2 + 8
	var pointer2 unsafe.Pointer = unsafe.Pointer(p2)
	var pi32 *int = (*int)(pointer2)

	fmt.Println(*px, *pf32, *pi32)

}
