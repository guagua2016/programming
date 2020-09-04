package main

import (
	"fmt"
)

type iquack interface {
	Quack() string
}

type Duck struct {
}

func (D *Duck) Quack() string {
	return "duck quack"
}

func main() {
	var c iquack = Duck{}
	ret := c.Quack()
	fmt.Println(ret)
}
