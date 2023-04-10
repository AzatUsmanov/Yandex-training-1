package main

import (
	"fmt"
)

func main() {
	var constant = true
	var ascending = true
	var weacklyAscending = true
	var descending = true
	var weacklyDescending = true
	var a []int
	var k int
	for {
		fmt.Scan(&k)
		if k == -2000000000 {
			break
		}
		a = append(a, k)
	}

	for i := 1; i < len(a); i++ {
		if a[i-1] != a[i] {
			constant = false
		}
		if a[i-1] >= a[i] {
			ascending = false
		}
		if a[i-1] > a[i] {
			weacklyAscending = false
		}
		if a[i-1] <= a[i] {
			descending = false
		}
		if a[i-1] < a[i] {
			weacklyDescending = false
		}
	}

	switch {
	case constant:
		fmt.Print("CONSTANT")
	case ascending:
		fmt.Print("ASCENDING")
	case descending:
		fmt.Print("DESCENDING")
	case weacklyAscending:
		fmt.Print("WEAKLY ASCENDING")
	case weacklyDescending:
		fmt.Print("WEAKLY DESCENDING")
	default:
		fmt.Print("RANDOM")
	}
}
