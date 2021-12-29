package main

import (
	"fmt"
)

func main() {
	var tc int
	var n int
	var m int

	fmt.Scan(&tc)
	for i := 0; i < tc; i++ {
		fmt.Scan(&n, &m)

		pairs := make([][]int, n)
		for j := 0; j < m; j++ {
			var a1, a2 int
			fmt.Scan(&a1, &a2)
			pairs[a1] = append(pairs[a1], a2)
			pairs[a2] = append(pairs[a2], a1)
		}

		answer := solve(&pairs, []int{}, 0)
		fmt.Println(answer)
	}
}
func solve(pairs *[][]int, consumed []int, start int) int {
	if start >= len(*pairs) {
		return 0
	}
	if len(consumed) == len(*pairs) {
		return 1
	}
	if Int(start).in(consumed) {
		return solve(pairs, consumed, start+1)
	}

	valid := 0

	for _, val := range (*pairs)[start] {
		if !Int(val).in(consumed) {
			valid += solve(pairs, append(consumed, start, val), +1)
		}
	}

	return valid
}

// Int wraps int
type Int int

func (x Int) in(target []int) bool {
	for _, val := range target {
		if val == int(x) {
			return true
		}
	}
	return false
}
