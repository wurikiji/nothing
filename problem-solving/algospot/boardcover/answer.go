package main

import (
	"fmt"
)

func main() {
	var c int
	var h, w int

	fmt.Scanln(&c)

	for ; c > 0; c-- {
		fmt.Scanln(&h, &w)

		board := make([]string, h)

		for i := 0; i < h; i++ {
			fmt.Scanln(&board[i])
		}

		mutableBoard := [][]byte{}
		for _, line := range board {
			mutableBoard = append(mutableBoard, []byte(line))
		}
		filled := [30][30]int{}
		for i := range filled {
			for j := range filled[i] {
				filled[i][j] = -1
			}
		}
		answer := solve(mutableBoard, 0, 0, filled)
		fmt.Println(answer)
	}
}

var dxArray = [][]int{
	{0, 1, 0}, // me, my down, my right
	{0, 0, 1}, // me, my right, my right down
	{0, 1, 1}, // me, my down, my down left
	{0, 1, 1}, // me, my down, my down right
}
var dyArray = [][]int{
	{0, 0, 1},  // me, below, right
	{0, 1, 1},  // right down
	{0, 0, -1}, // down left
	{0, 0, 1},  // down right
}

var step = 0

func solve(board [][]byte, x, y int, filled [30][30]int) int {
	var nx = -1
	var ny = -1

	for ; x < len(board); x++ {
		for ; y < len(board[x]); y++ {
			if board[x][y] == '.' && filled[x][y] == -1 {
				nx = x
				ny = y
				break
			}
		}
		if ny != -1 {
			break
		}
		y = 0
	}

	if ny == -1 {
		// everything is filled
		return 1
	}

	answer := 0

	for idx := range dxArray {
		canFill := fill(board, nx, ny, idx, &filled)
		if canFill {
			answer += solve(board, nx, ny+1, filled)
		}
		unfill(board, nx, ny, idx, &filled)
	}
	return answer
}

func printBoard(board [][]byte, filled [30][30]int) {
	for i := range board {
		for j := range board[i] {
			fmt.Printf("%4d ", filled[i][j])
		}
		fmt.Println()
	}
}
func inBound(board [][]byte, x, y int) bool {
	return 0 <= x && x < len(board) && 0 <= y && y < len(board[0])
}

func fill(board [][]byte, x, y, idx int, filled *[30][30]int) bool {
	dx := dxArray[idx]
	dy := dyArray[idx]

	for i := range dx {
		nx := x + dx[i]
		ny := y + dy[i]
		if inBound(board, nx, ny) && board[nx][ny] == '.' && filled[nx][ny] == -1 {
			filled[nx][ny] = x*30 + y
		} else {
			return false
		}
	}
	return true
}

func unfill(board [][]byte, x, y, idx int, filled *[30][30]int) {
	dx := dxArray[idx]
	dy := dyArray[idx]

	for i := range dx {
		nx := x + dx[i]
		ny := y + dy[i]
		if inBound(board, nx, ny) && filled[nx][ny] == x*30+y {
			filled[nx][ny] = -1
		} else {
			break
		}
	}
}
