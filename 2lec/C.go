package main

import (
	"fmt"
	"math"
)

func main() {
	var n, x, min, mini int
	min = 10000
	fmt.Scan(&n)
	a := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	fmt.Scan(&x)
	for i := 0; i < n; i++ {
		if int(math.Abs(float64(a[i]-x))) < min {
			min = int(math.Abs(float64(a[i] - x)))
			mini = i
		}
	}
	if n > 0 {
		fmt.Print(a[mini])
	}
}
