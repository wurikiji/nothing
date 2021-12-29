package main

import (
	"fmt"
)

func square(a int) int {
	return a * a
}

func main() {
	fmt.Printf("9 * 9 = %d\n", square(9))
}
