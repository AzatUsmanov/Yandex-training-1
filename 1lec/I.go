package main

import (
	"fmt"
)

func main() {
	var a, b, c, d, e int
	fmt.Scan(&a, &b, &c, &d, &e)
	if a < 0 || b < 0 || c < 0 || d < 0 || e < 0 {
		fmt.Print("NO")
		return
	}
	f := func(x, y int) bool {
		return (d >= x && e >= y) || (d >= y && e >= x)
	}
	if f(a, b) || f(b, c) || f(a, c) {
		fmt.Print("YES")
	} else {
		fmt.Print("NO")
	}
}
