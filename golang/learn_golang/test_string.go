package main

import (
	"fmt"
	"strconv"
)

func main() {

	s := strconv.Itoa(156)
	a, err := strconv.Atoi(s)

	fmt.Println(s, a, err)
}
