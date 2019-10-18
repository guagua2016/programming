package main

import (
	"errors"
	"fmt"
)

type Person struct {
	Name string
	age  int
}

func main() {

	//defer
	defer func() {
		fmt.Println("defer func(){}()")
		if r := recover(); r != nil {
			fmt.Println("Runtime error caught!", r)
		}
	}()

	//Type Assertion
	var v interface{}
	v = Person{"bob", 12}
	if f, ok := v.(Person); ok {
		fmt.Println(f.Name)
	}

	panic("throw a panic")

	fmt.Println("hello,world")
}
