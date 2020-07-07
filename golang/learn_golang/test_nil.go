package main

import (
	"fmt"
)

type Person struct {
	AgeYears int
	Name     string
	Friends  []Person
}

func main() {
	var p Person
	fmt.Printf("%v\n", p)

	var slice1 []int
	fmt.Println(slice1)
	if slice1 == nil {
		fmt.Println("slice1 is nil")
	}
	// fmt.Println(slice1[0])  panic

	// var c chan int
	// close(c)  panic
}
