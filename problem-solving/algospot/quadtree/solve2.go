package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		var image string
		fmt.Scan(&image)
		answer, _ := solve(&image, 0)
		fmt.Println(answer)
		t--
	}
}

func solve(image *string, start int) (string, int) {
	if (*image)[start] != 'x' {
		return string((*image)[start]), 1
	}

	start++
	first, len1 := solve(image, start)
	start += len1
	second, len2 := solve(image, start)
	start += len2
	third, len3 := solve(image, start)
	start += len3
	fourth, _ := solve(image, start)
	answer := "x" + third + fourth + first + second
	return answer, len(answer)
}
