package main

import (
	// "bufio"
	"fmt"
	// "io"
	// "io/ioutil"
	"os" //
)

func main() {
	f, err := os.Create("./os_create.txt")
	if err != nil {
		fmt.Println(err)
	}

	s1 := "你好,world"
	data := []byte(s1)
	n, err := f.Write(data)
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Printf("write %d byte\n", n)
	}
}
