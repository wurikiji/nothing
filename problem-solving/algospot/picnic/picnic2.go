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
		areFriends := [10][10]bool{}
		fmt.Scan(&n, &m)
		for j := 0; j < m; j++ {
			var a1, a2 int
			fmt.Scan(&a1, &a2)
			areFriends[a1][a2] = true
			areFriends[a2][a1] = true
		}
		found := make([]bool, n)
		answer := solve(&areFriends, &found)
		fmt.Println(answer)
	}
}
func solve(areFriends *[10][10]bool, found *[]bool) int {
	notFound := -1
	for idx, val := range *found {
		if !val {
			notFound = idx
			break
		}
	}
	if notFound == -1 {
		return 1
	}
	answer := 0
	(*found)[notFound] = true
	for i := notFound + 1; i < len(*found); i++ {
		if !(*found)[i] && areFriends[i][notFound] {
			(*found)[i] = true
			answer += solve(areFriends, found)
			(*found)[i] = false
		}
	}
	(*found)[notFound] = false

	return answer
}
