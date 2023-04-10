package main

import (
	"fmt"
	"math"
)

func minf(m map[int]int) int {
	min := 100000000
	mini := 0
	for i, v := range m {
		if min > i * v {
			min = i * v
			mini = i
		}
	}
	return mini
}

func main() {
	var (
		a, b, c, d int
	)
	fmt.Scan(&a, &b, &c, &d)
	m := make(map[int]int)
	m[a+c] = int(math.Max(float64(d), float64(b)))
	m[a+d] = int(math.Max(float64(b), float64(c)))
	m[b+c] = int(math.Max(float64(d), float64(a)))
	m[b+d] = int(math.Max(float64(a), float64(c)))
	p := minf(m)
	fmt.Print(p, m[p])
}