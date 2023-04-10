package main

import "fmt"

func main() {
	var (
		n, k, temp int
	)
	fmt.Scan(&n)
	c := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&temp)
		c[i] = temp
	}
	fmt.Scan(&k)
	for i := 0; i < k; i++ {
		fmt.Scan(&temp)
		c[temp-1]--
	}
	for i := 0; i < n; i++ {
		if c[i] < 0 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
