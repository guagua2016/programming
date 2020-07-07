package main

import (
	"fmt"
	"reflect"
	"unsafe"
)

func string2byte(s string) []byte {
	sh := (*reflect.StringHeader)(unsafe.Pointer(&s))
	bh := reflect.SliceHeader{
		Data: sh.Data,
		Len:  sh.Len,
		Cap:  sh.Len,
	}
	return *(*[]byte)(unsafe.Pointer(&bh))
}

func byte2string(b []byte) string {
	bh := (*reflect.SliceHeader)(unsafe.Pointer(&b))
	sh := reflect.StringHeader{
		Data: bh.Data,
		Len:  bh.Len,
	}
	return *(*string)(unsafe.Pointer(&sh))
}

func main() {
	var n int64 = 5
	var pn = &n
	fmt.Printf("==%x,%x,%x\n", uintptr(unsafe.Pointer(pn)), pn, unsafe.Pointer(pn))

	var pf = (*float64)(unsafe.Pointer(pn))
	// now, pn and pf are pointing at the same memory address
	fmt.Println(*pf) // 2.5e-323
	*pf = 3.14159
	fmt.Println(n) // 4614256650576692846

	fmt.Println(unsafe.Sizeof(n))

	b := string2byte("abc***##22")
	fmt.Println(b)
	s := byte2string(b)
	fmt.Println(s)

	u := reflect.ValueOf(new(int)).Pointer()
	p := (*int)(unsafe.Pointer(u))
	fmt.Println("48", *p)
	type TwoBool struct {
		one bool
		two bool
	}
	var v TwoBool
	fmt.Println(unsafe.Sizeof(v))

	var x struct {
		b int16
		c []int
		a bool
	}
	fmt.Println(unsafe.Sizeof(x))
	tmp := uintptr(unsafe.Pointer(&x)) + unsafe.Offsetof(x.b)
	pb := (*int16)(unsafe.Pointer(tmp))
	*pb = 42
	fmt.Println(*pb)

	// pT := uintptr(unsafe.Pointer(new(int))) // 提示: 错误!
	// fmt.Println(*pT)

	var a, c []string = nil, []string{}
	fmt.Println(reflect.DeepEqual(a, c))

	var d, e map[string]int = nil, make(map[string]int)
	fmt.Println((reflect.DeepEqual(d, e)))
}
