package main

import (
	"fmt"
	"io"
	"runtime"
	"runtime/debug"
	"unsafe"
)

type Reader struct {
	r    io.Reader
	skip int64
	blk  block
	err  error
}

type block [64]byte

func main() {
	r := Reader{}

	var ir io.Reader
	var er error

	fmt.Println(unsafe.Sizeof(ir))
	fmt.Println(unsafe.Sizeof(er))
	fmt.Println(unsafe.Sizeof(r))
	runtime.GC()
	fmt.Println("hello,world")
	fmt.Println(debug.SetGCPercent(200))
	fmt.Println(debug.SetGCPercent(200))
}
