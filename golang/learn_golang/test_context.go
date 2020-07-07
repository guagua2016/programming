package main

import (
	"context"
	"fmt"
	"time"
)

func main() {
	ctx, cancel := context.WithCancel(context.Background())
	context.TODO()

	valueCtx := context.WithValue(ctx, key, "fdsf")

	go watch(valueCtx)
	time.Sleep(10 * time.Second)
	cancel()

	time.Sleep(5 * time.Second)
}

func watch(ctx context.Context) {
	for {
		select {
		case <-ctx.Done():
			//get value
			fmt.Println(ctx.Value(key), "is cancel")

			return
		default:
			//get value
			fmt.Println(ctx.Value(key), "int goroutine")

			time.Sleep(2 * time.Second)
		}
	}
}

// func main() {
// 	d := time.Now().Add(4 * time.Second)
// 	ctx, cancel := context.WithDeadline(context.Background(), d)

// 	// Even though ctx will be expired, it is good practice to call its
// 	// cancelation function in any case. Failure to do so may keep the
// 	// context and its parent alive longer than necessary.

// 	go func(ctx context.Context) {
// 		fmt.Println(ctx.Err())
// 		for {
// 			select {
// 			case <-time.After(10 * time.Second):
// 				fmt.Println("oversleep")
// 				return
// 			case <-ctx.Done():
// 				fmt.Println(ctx.Err())
// 				return
// 			}
// 		}

// 	}(ctx)
// 	defer cancel()

// 	time.Sleep(5 * time.Second)
// }
