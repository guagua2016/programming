package main

import (
	"fmt"
	_ "util"
)

var a int = func() int {
	fmt.Println("main variable init")
	return 3
}()

func init() {
	fmt.Println("call main.init")
}

func main() {
	fmt.Println("call main.main")
}
