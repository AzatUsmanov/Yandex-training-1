package main

import (
	"fmt"
	"math"
)

func main() {
	var (
		a                       []float64
		s                       string
		max, min, n, diff, temp float64 = 4000, 30, 0, 0, 0
	)
	fmt.Scan(&n, &temp)
	a = append(a, temp)
	for i := 1; i < int(n); i++ {
		fmt.Scan(&temp, &s)
		a = append(a, temp)
		diff = math.Abs((a[i-1] - a[i]) / 2)
		switch {
		case a[i] > a[i-1] && s == "further":
			{
				if a[i]-diff < max {
					max = a[i] - diff
				}
			}
		case a[i] < a[i-1] && s == "further":
			{
				if a[i]+diff > min {
					min = a[i] + diff
				}
			}
		case a[i] > a[i-1] && s == "closer":
			{
				if a[i]-diff > min {
					min = a[i] - diff
				}
			}
		case a[i] < a[i-1] && s == "closer":
			{
				if a[i]+diff < max {
					max = a[i] + diff
				}
			}
		}
	}
	fmt.Print(min, max)
}
