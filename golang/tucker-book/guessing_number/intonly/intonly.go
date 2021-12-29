package intonly

import (
	"bufio"
	"fmt"
	"os"
)

var stdin = bufio.NewReader(os.Stdin)

func Input() (int, bool) {
	var input int
	isInt := true
	_, err := fmt.Scanln(&input)
	if err != nil {
		stdin.ReadString('\n')
		isInt = false
	}
	return input, isInt
}
