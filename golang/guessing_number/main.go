package main

import (
	"fmt"
	"guessing_number/intonly"
	"math/rand"
	"time"
)

func init() {
	fmt.Println("초기화 중입니다.")
	rand.Seed(time.Now().UnixNano())

}

func main() {
	var randomInt = rand.Intn(100)
	i := 1
	for ; ; i++ {
		fmt.Print("숫자값을 입력하세요: ")
		userInput, isInt := intonly.Input()
		if !isInt {
			continue
		}
		if userInput == randomInt {
			break
		}
		if userInput < randomInt {
			fmt.Println("입력한 숫자가 더 낮습니다.")
		} else {
			fmt.Println("입력한 숫자가 더 높습니다.")
		}
	}
	fmt.Println("정답입니다. 숫자는", randomInt, "입니다.", "시도한 횟수는", i, "회 입니다.")
}
