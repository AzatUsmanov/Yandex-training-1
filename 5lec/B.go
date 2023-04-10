package main

import "fmt"

func main() {
	var n int
	var ans, k int64
	fmt.Scan(&n, &k)
	a := make([]int64, n, n)
	sum := make([]int64, n+1, n+1)
	m := make(map[int64]int64)
	m[0]++
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 1; i < n+1; i++ {
		sum[i] = sum[i-1] + a[i-1]
		m[sum[i]]++
		if val, ok := m[sum[i]-k]; ok {
			ans += val
		}
	}
	fmt.Println(ans)
}
