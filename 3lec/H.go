package main

import (
	"fmt"
)

type set struct {
	a [163][]int
}

func (c *set) Hash(x int) int {
	return ((x % 17) * 7) % 163
}

func (c *set) Add(x int) {
	hash := c.Hash(x)
	if !c.Find(x) {
		c.a[hash] = append(c.a[hash], x)
	}
}

func (c *set) Find(x int) bool {
	hash := c.Hash(x)
	for i := 0; i < len(c.a[hash]); i++ {
		if c.a[hash][i] == x {
			return true
		}
	}
	return false
}

func (c *set) FindCount() int {
	var count int
	for i := 0; i < len(c.a); i++ {
		count += len(c.a[i])
	}
	return count
}

func (c *set) Del(x int) bool {
	hash := c.Hash(x)
	for i := 0; i < len(c.a[hash]); i++ {
		if c.a[hash][i] == x {
			c.a[hash] = append(c.a[hash][0:i], c.a[hash][i+1:]...)
			return true
		}
	}
	return false
}

func main() {
	var (
		x, y, n int
		s       set
	)
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x, &y)
		s.Add(x)
	}
	fmt.Println(s.FindCount())
}
