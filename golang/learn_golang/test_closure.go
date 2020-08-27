package main

import (
	"fmt"
)

func foo(x int) func() {
	return func() {
		x = x + 1
		fmt.Println("foo x=", x)
	}
}

func foo1(x *int) func() {
	return func() {
		*x = *x + 1
		fmt.Println("foo1 x=", *x)
	}
}

func foo2() {
	values := []int{1, 2, 3, 4, 5}
	// var wg sync.WaitGroup
	for _, v := range values {
		go fmt.Println(v)
	}
}

func foo3() {
	values := []int{1, 2, 3, 4, 5}
	// var wg sync.WaitGroup
	for _, v := range values {
		go func() { fmt.Println(v) }()
	}
}

func foo4() {
	values := []int{1, 2, 3, 4, 5}
	// var wg sync.WaitGroup
	for _, v := range values {
		go func(x int) { fmt.Println(x, v) }(v)
	}
}

func fibonacci() func() int {
	b1 := 1
	b2 := 0
	b3 := 0
	return func() int {
		b3 = b1 + b2
		b1 = b2
		b2 = b3
		return b3
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
