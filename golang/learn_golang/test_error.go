package main

import (
	"errors"
	"fmt"
)

type MyError struct {
	ErrorInfo string
}

func (e *MyError) Error() string {
	return e.ErrorInfo
}

func foo() error {
	return errors.New("foo error")
}

func main() {
	err := foo()
	if err != nil {
		fmt.Println(err)
	}
}
