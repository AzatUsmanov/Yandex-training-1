package main

import "fmt"

func isSymmetric(a []int, index int) bool {
	for i := index; i < len(a); i++ {
		if a[i] != a[len(a)-1-i+index] {
			return false
		}
	}
	return true
}

func main() {
	var (
		n, index int
		a        []int
	)
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&index)
		a = append(a, index)
	}
	for i := n - 1; i >= 0; i-- {
		if isSymmetric(a, i) {
			index = i
		}
	}
	fmt.Println(index)
	for i := index - 1; i >= 0; i-- {
		fmt.Print(a[i], " ")
	}
}
