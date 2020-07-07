package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"time"
)

func main() {

	l, err := net.Listen("tcp", "127.0.0.1:8080")
	if err != nil {
		fmt.Println("Error listening...")
		os.Exit(1)
	}
	defer l.Close()

	for {
		conn, err := l.Accept()
		if err != nil {
			fmt.Println("Error Accepting...")
			os.Exit(2)
		}

		fmt.Printf("Receive message %s -> %s\n", conn.RemoteAddr(), conn.LocalAddr())
		go handleRequest(conn)
	}
}

func handleRequest(conn net.Conn) {

	conn.SetDeadline(time.Now().Add(time.Duration(1) * time.Second))

	reader := bufio.NewReader(conn)
	defer conn.Close()
	for {
		message, err := reader.ReadString('\n')
		if err != nil {
			os.Exit(3)
		}
		fmt.Println(string(message))
		conn.Write([]byte(message))
	}
}
