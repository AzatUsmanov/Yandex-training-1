package main

import (
	"fmt"
)

func main() {
	var (
		a, b, c int
	)
	fmt.Scan(&a, &b, &c)
	if c < 0 {
		fmt.Print("NO SOLUTION")
	} else if a == 0 && c*c == b {
		fmt.Println("MANY SOLUTIONS")
	} else if a == 0 {
		fmt.Print("NO SOLUTION")
	} else if (c*c - b) % a == 0 {
		fmt.Print((c*c - b) / a)
	} else {
		fmt.Print("NO SOLUTION")
	}
}