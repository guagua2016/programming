package main

import (
	"fmt"
	"sync"
	"time"
)

var (
	mu      sync.RWMutex // guards balance
	balance int
)

func Withdraw(amount int) bool {
	mu.Lock()
	defer mu.Unlock()
	deposit(-amount)
	if balance < 0 {
		deposit(amount)
		return false // insufficient funds
	}
	return true
}

func Deposit(amount int) {
	mu.Lock()
	defer mu.Unlock()
	deposit(amount)
}

func Balance() int {
	mu.RLock()
	defer mu.RUnlock()
	return balance
}

// This function requires that the lock be held.
func deposit(amount int) { balance += amount }

func main() {
	Deposit(100)
	for i := 0; i < 1000; i++ {
		go func() {
			fmt.Println(Balance())
		}()
	}

	for i := 0; i < 10; i++ {
		go func() {
			Deposit(10)
			fmt.Println("===", Balance())
		}()

	}
	time.Sleep(10 * time.Second)
}
