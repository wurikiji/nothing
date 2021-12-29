package main

import (
	"fmt"
)

// Add a and b
func Add(a int, b int) int {
	return a + b
}

func main() {
	c := Add(3, 6)
	fmt.Println(c)
}
