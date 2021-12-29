package main

import "fmt"

func main() {
	a := 3
	b := float64(3.5)
	c := int(b)
	d := float64(a * c)
	e := int64(7)
	f := int64(d) * e
	g := int(b * 3)
	h := int(b) * 3
	fmt.Println(g, h, f)

}
