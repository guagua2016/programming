package main

import (
	"fmt"
	"time"
)

var balance int

func Deposit(amount int) { balance = balance + amount }
func Balance() int       { return balance }

func main() {
	go func() {
		Deposit(200)                // A1
		fmt.Println("=", Balance()) // A2
	}()

	go Deposit(100) // B

	time.Sleep(10 * time.Second)
}
