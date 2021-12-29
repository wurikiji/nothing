package main

import (
	"fmt"
	"sync"
	"time"
)

var wg sync.WaitGroup

func PrintHangul() {
	hanguls := []rune{'가', '나', '다', '라', '마', '바', '사'}
	for _, v := range hanguls {
		time.Sleep(300 * time.Millisecond)
		fmt.Printf("%c ", v)
	}
	wg.Done()
}

func PrintNubmers() {
	for i := 1; i <= 5; i++ {
		time.Sleep(400 * time.Millisecond)
		fmt.Printf("%d ", i)
	}
	wg.Done()
}
func main() {
	wg.Add(2)
	go PrintHangul()
	go PrintNubmers()

	time.Sleep(3 * time.Second)
	wg.Wait()
}
