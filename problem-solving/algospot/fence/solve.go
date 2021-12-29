package main

import (
	"fmt"
)

func main() {
	var c int
	fmt.Scan(&c)

	for ; c > 0; c-- {
		var n int
		fmt.Scan(&n)
		arr := make([]int, n)
		for idx := range arr {
			fmt.Scan(&arr[idx])
		}
		fmt.Println(solve(arr))
	}
}

func solve(arr []int) int {
	if len(arr) == 0 {
		return 0
	}
	if len(arr) == 1 {
		return arr[0]
	}
	mid := len(arr) / 2
	leftMax := solve(arr[:mid])
	rightMax := solve(arr[mid:])
	midMax := findMidMax(arr)

	return max(leftMax, max(rightMax, midMax))
}

func findMidMax(arr []int) int {
	mid := len(arr) / 2
	left, right := mid-1, mid
	minHeight := min(arr[left], arr[right])
	ret := minHeight * 2
	for left > 0 || right+1 < len(arr) {
		if left > 0 && (right+1 == len(arr) || arr[left-1] > arr[right+1]) {
			left--
			minHeight = min(minHeight, arr[left])
		} else {
			right++
			minHeight = min(minHeight, arr[right])
		}
		ret = max(ret, minHeight*(right-left+1))
	}
	return ret
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}
func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}
