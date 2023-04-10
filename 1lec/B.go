package main

import "fmt"

func main() {
	var (
		a, b, c int
	)
	fmt.Scan(&a, &b, &c)
	switch {
	case a >= b+c:
		fmt.Print("NO")
	case b >= a+c:
		fmt.Print("NO")
	case c >= a+b:
		fmt.Print("NO")
	default:
		fmt.Print("YES")
	}
}