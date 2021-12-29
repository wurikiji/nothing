package main

import "fmt"

var controller = [10][]int{
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13},
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		var clock [16]int
		for idx := range clock {
			fmt.Scan(&clock[idx])
		}
		fmt.Println(solve(&clock, 0, 0))
	}
}

func solve(clock *[16]int, controllerIdx int, clicked int) int {
	if controllerIdx == 10 {
		if checkSolved(clock) {
			return clicked
		}
		return -1
	}
	var ret = -1
	for i := 0; i < 4; i++ {
		answer := solve(clock, controllerIdx+1, clicked+i)
		if answer != -1 {
			if ret == -1 {
				ret = answer
			} else if ret > answer {
				ret = answer
			}
		}
		// 4번 클릭하면 원상 복귀 됨
		tick(clock, controller[controllerIdx])
	}
	return ret
}

func tick(clock *[16]int, targets []int) {
	for _, target := range targets {
		clock[target] += 3
	}
}

func checkSolved(clock *[16]int) bool {
	for _, ctime := range clock {
		if (ctime % 12) != 0 {
			return false
		}
	}
	return true
}
