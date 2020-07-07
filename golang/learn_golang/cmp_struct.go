package main

import "fmt"

func main() {
	var c chan int

	select {
	case c <- 0:
		fmt.Printf("received 0")
	case c <- 1:
		fmt.Printf("sent 1")
	}

}
