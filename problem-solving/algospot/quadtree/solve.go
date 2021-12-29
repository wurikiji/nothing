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
		solve(image)
		fmt.Println()
		t--
	}
}

func solve(image string) {

	fmt.Printf("%c", image[0])

	if len(image) == 1 {
		return
	}

	first, lastPosition := nextQuarter(image, 1)
	second, lastPosition := nextQuarter(image, lastPosition)
	third, lastPosition := nextQuarter(image, lastPosition)
	fourth, lastPosition := nextQuarter(image, lastPosition)
	solve(third)
	solve(fourth)
	solve(first)
	solve(second)
}

func nextQuarter(image string, start int) (string, int) {
	i := start
	for consume := 1; consume > 0; consume-- {
		if image[i] == 'x' {
			consume += 4
		}
		i++
	}
	return image[start:i], i
}
