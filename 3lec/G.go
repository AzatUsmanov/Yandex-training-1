package main

import (
	"fmt"
	"math"
)

type pair struct {
	x, y int
}

type set struct {
	a [20000][]pair
}

func (c *set) Hash(x pair) int {
	return (int(math.Abs(float64(x.x))) + int(math.Abs(float64(x.x)))) % len(c.a)
}

func (c *set) Add(x pair) {
	hash := c.Hash(x)
	if !c.Find(x) {
		c.a[hash] = append(c.a[hash], x)
	}
}

func (c *set) Find(x pair) bool {
	hash := c.Hash(x)
	for i := 0; i < len(c.a[hash]); i++ {
		if c.a[hash][i].x == x.x && c.a[hash][i].y == x.y {
			return true
		}
	}
	return false
}

func (c *set) Del(x pair) bool {
	hash := c.Hash(x)
	for i := 0; i < len(c.a[hash]); i++ {
		if c.a[hash][i].x == x.x && c.a[hash][i].y == x.y {
			c.a[hash] = append(c.a[hash][0:i], c.a[hash][i+1:]...)
			return true
		}
	}
	return false
}

func main() {
	n, count := 0, 0
	temp := pair{0, 0}
	s := set{}
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		s.Add(pair{i, n - i - 1})
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&temp.x, &temp.y)
		if s.Del(temp) {
			count++
		}
	}
	fmt.Println(count)
}
