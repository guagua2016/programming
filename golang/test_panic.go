package main

import (
	// "errors"
	"fmt"
	"time"
)

type Person struct {
	Name string
	age  int
}

func f() {
	for {
		time.Sleep(2 * time.Second)
		fmt.Println(t())
	}
}

func t() int32 {

	//defer
	var ret int32
	ret = 10
	defer func(ret int32) int32 {
		fmt.Println("defer func(){}()")
		if r := recover(); r != nil {
			// fmt.Println("Runtime error caught!", r)
		}
		return ret
	}()

	panic("throw a panic")
	ret = ret + 1
	return ret
}

func main() {
	go f()
	for {

	}
}
