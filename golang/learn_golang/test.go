package main

import (
	"fmt"
)

type Person struct {
	age  int32
	name string
}

func main() {

	s1 := [3]int{1, 2, 3}
	s2 := s1
	s1[1] = 100

	fmt.Printf("%+v,%+v\n", s1, s2)

	var p2 Person
	p1 := &Person{}
	p1.age = 10
	p1.name = "nnn"

	p2 = *p1

	fmt.Printf("%+v,%+v\n", *p1, p2)
}
