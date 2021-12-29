package main

import (
	"context"
	"fmt"
	"sync"
)

var wg sync.WaitGroup

func square(ctx context.Context) {
	if v := ctx.Value("number"); v != nil {
		n := v.(int)
		fmt.Printf("Square : %d\n", n*n)
	}
	wg.Done()
}

func main() {
	wg.Add(1)
	ctx := context.WithValue(context.Background(), "number", 9)
	go square(ctx)
	wg.Wait()
}
