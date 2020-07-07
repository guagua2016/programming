package main

import (
	"fmt"
	// "sync"
	// "time"
)

func main() {
	ready := make(chan bool)
	close(ready)
	<-ready
	fmt.Println("end")
}
