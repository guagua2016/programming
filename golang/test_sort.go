package main

import (
	"fmt"
	"sort"
)

func main() {

	s1 := []int{10, 1, 3, 5, 6, 7, 2, 4, 6}
	sort.Ints(s1)
	fmt.Println(s1)

	sort.Sort(sort.Reverse(sort.IntSlice(s1)))
	fmt.Println(s1)
}
