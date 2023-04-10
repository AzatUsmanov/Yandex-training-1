package main

import "fmt"

func main() {
	var n, k, m, K, M int
	fmt.Scan(&n, &k, &m)
	for {
		if (n-(n%k))/k == 0 {
			break
		}
		K += (n - (n % k)) / k
		n -= K * k
		if K*(k-(k%m))/m == 0 {
			break
		}
		M += K * (k - (k % m)) / m
		n += K * (k % m)
		K = 0
	}
	fmt.Print(M)
}
