package util

import (
	"fmt"
)

var c int = func() int {
	fmt.Println("util variable init")
}()

func init() {
	fmt.Println("call util.init")
}
