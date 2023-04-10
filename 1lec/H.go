package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, n, m int
	fmt.Scan(&a, &b, &n, &m)
	amax := (a+1)*n + a
	bmax := (b+1)*m + b
	amin := (a+1)*n - a
	bmin := (b+1)*m - b
	if bmin > amax || amin > bmax {
		fmt.Print(-1)
	} else {
		fmt.Print(int(math.Max(float64(amin), float64(bmin))), int(math.Min(float64(amax), float64(bmax))))
	}
}