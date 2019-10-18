package main

import (
	"fmt"
)

type testSlice []int

func (t testSlice) changeSlice(c int) []int {
	return append(t, c)
}

type stu struct {
	test_slice []int
	test_int   int
	test_map   map[string]int
}

func (s stu) foo1(val int) []int {
	s.test_slice = append(s.test_slice, val)
	// fmt.Println(s.test_slice)
	// return append(s.test_slice, 1)
	return append(s.test_slice, val)
}

func (s stu) fool2() {
	s.test_map["test"] = 100
}

func main() {
	s := &stu{
		test_map: make(map[string]int),
	}
	s.foo1(2)
	s.fool2()
	fmt.Printf("%+v\n", s)

	t := &testSlice{}
	t.changeSlice(2)
	fmt.Println(t)
}
