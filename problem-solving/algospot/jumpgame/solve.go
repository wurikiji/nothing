package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var c int
	fastScan(&c, scanner)
	for ; c > 0; c-- {
		var n int
		fastScan(&n, scanner)
		board := make([][]int, n, n)
		for i := range board {
			board[i] = make([]int, n, n)
		}
		board[0][0] = 1
		for i := 0; i < n; i++ {
			scanner.Scan()
			line := strings.NewReader(scanner.Text())
			for j := 0; j < n; j++ {
				var jump int
				fmt.Fscan(line, &jump)
				if board[i][j] != 1 {
					continue
				}
				if jump+i < n {
					board[i+jump][j] = 1
				}
				if j+jump < n {
					board[i][j+jump] = 1
				}
			}
		}
		if board[n-1][n-1] == 1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func fastScan(input *int, scanner *bufio.Scanner) {
	scanner.Scan()
	*input, _ = strconv.Atoi(scanner.Text())
}
