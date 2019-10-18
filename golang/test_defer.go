package main

import (
	"fmt"
)

func f() (ret int) {
	defer func() {
		ret++
	}()
	return 0
}

func f2() (ret int) {
	r := 5
	defer func() {
		r = r + 5
	}()
	return r
}

func f3() (r int) {
	defer func(r int) {
		r = r + 5
	}(r)
	return 1
}

func f4() (r int) {
	defer func(r *int) {
		*r = *r + 5
	}(&r)
	return 1
}

func main() {
	fmt.Println(f())
	fmt.Println(f2())
	fmt.Println(f3())
	fmt.Println(f4())
}
