package main

import (
	"fmt"
)

func main() {
	a := make([]int, 0, 0)
	n, k, vas, number, max := 0, 0, 0, 0, 0
	flag := false

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&k)
		a = append(a, k)
	}

	for i := 0; i < len(a); i++ {
		if a[i] > max {
			max = a[i]
		}
	}

	for i := 0; i < n-1; i++ {
		if a[i] == max && !flag {
			flag = true
			continue
		}
		if flag && a[i]%10 == 5 && a[i] > vas && a[i+1] < a[i] {
			vas = a[i]
		}
	}

	for i := 0; i < len(a); i++ {
		if a[i] > vas {
			number++
		}
	}

	if vas > 0 {
		fmt.Print(number + 1)
	} else {
		fmt.Println(vas)
	}
}

