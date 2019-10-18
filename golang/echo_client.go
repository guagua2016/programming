package main

import (
	"fmt"
	"net"
	"os"
	"time"
	// "strconv"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:8080")
	if err != nil {
		fmt.Println("Error Dial....")
		os.Exit(1)
	}
	defer conn.Close()

	fmt.Printf("Connectiong to %s\n", conn.RemoteAddr())

	for {
		_, err = conn.Write([]byte("hello " + "\r\n"))
		if err != nil {
			fmt.Println("Error to send message because of", err.Error())
			os.Exit(2)
		}

		buf := make([]byte, 1024)
		reqLen, err := conn.Read(buf)
		if err != nil {
			fmt.Println("Error to read message because of ", err.Error())
			return
		}
		fmt.Println(string(buf[:reqLen-1]))
		time.Sleep(3 * time.Second)
	}

}
