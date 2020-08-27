package main

func foo1() *int {
	var x int
	x = 1
	return &x
}

func foo2() *int {
	x := new(int)
	return x
}

func main() {
	foo1()
	foo2()
}
