package main

import (
	"fmt"
	"reflect"
)

type Person struct {
	age   int
	name  string
	grade []int
}

func main() {

	p1 := Person{
		age:   1,
		name:  "aaa",
		grade: []int{1, 2, 3},
	}
	p2 := Person{1, "aaa", []int{1, 2, 3}}

	fmt.Println(reflect.TypeOf(p1) == reflect.TypeOf(p2))
	// fmt.Println(p1 == p2)
	// fmt.Println(reflect.Value(p1) == reflect.Value(p2))
	fmt.Println(reflect.DeepEqual(p1, p2))

	s1 := []int{1, 2, 3}
	s2 := []int{1, 2, 3}
	// fmt.Println(s1 == s2)
	fmt.Println(reflect.DeepEqual(s1, s2))
}
