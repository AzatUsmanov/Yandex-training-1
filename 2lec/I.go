package main

import "fmt"

func Up(x, y, n, m int, a *[][]int) {
	for i := -1; i <= 1; i++ {
		for j := -1; j <= 1; j++ {
			if i == 0 && j == 0 {
				continue
			}
			if x+i >= 0 && x+i < n && y+j < m && y+j >= 0 {
				if (*a)[x+i][y+j] != -1 {
					(*a)[x+i][y+j]++
				}
			}
		}
	}
}

func main() {
	n, m, k, x, y := 0, 0, 0, 0, 0
	fmt.Scan(&n, &m, &k)
	a := make([][]int, n, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m, m)
	}
	for i := 0; i < k; i++ {
		fmt.Scan(&x, &y)
		a[x-1][y-1] = -1
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if a[i][j] == -1 {
				Up(i, j, n, m, &a)
			}
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if a[i][j] == -1 {
				fmt.Print("* ")
			} else {
				fmt.Print(a[i][j], " ")
			}
		}
		fmt.Println()
	}
}
