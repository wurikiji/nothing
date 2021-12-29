package main

import "fmt"

func main() {
	fmt.Println("-----default")
	var t = [5]float64{24.0, 35.9, 27.8, 36.9, 26.2}
	for i := 0; i < len(t); i++ {
		fmt.Println(t[i])
	}

	fmt.Println()
	fmt.Println("--------skipped size")
	u := [...]string{"monday", "tuesday"}
	for _, val := range u {
		fmt.Println(val)
	}

	fmt.Println()
	fmt.Println("---------Positioned initializer")
	arr := [5]int{1: 10, 4: 30}
	for _, val := range arr {
		fmt.Println(val)
	}
}
