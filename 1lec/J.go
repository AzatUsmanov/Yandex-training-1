package main

import (
	"fmt"
	"math"
)

func equal(a, b, c, d float64) bool {
	if b != 0 && d != 0 {
		return a/b == c/d
	}
	return false
}

func main() {
	var a, b, c, d, e, f float64
	fmt.Scan(&a, &b, &c, &d, &e, &f)
	det := a*d - b*c
	if det != 0 {
		x := (e*d - b*f) / det
		y := (a*f - e*c) / det
		fmt.Printf("2 %.5f %.5f", x, y)
	} else {
		switch {
		case a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0:
			{
				fmt.Print(5)
			}
		case a == 0 && b == 0 && c == 0 && d == 0 && (e != 0 || f != 0):
			{
				fmt.Print(0)
			}
		case equal(c, a, d, b) && b != 0 && e != 0 && d/b != f/e:
			{
				fmt.Print(0)
			}
		case equal(c, a, d, b) && b != 0 && e == 0 && f == 0 && math.Abs(d/b) != 1:
			{
				fmt.Print(0)
			}
		case equal(c, a, b, d) && a != 0 && e != 0 && c/a != f/e:
			{
				fmt.Print(0)
			}
		case equal(c, a, b, d) && a != 0 && e == 0 && f == 0 && math.Abs(c/a) != 1:
			{
				fmt.Print(0)
			}
		case equal(a, c, b, d) && d != 0 && f != 0 && b/d != e/f:
			{
				fmt.Print(0)
			}
		case equal(a, c, b, d) && d != 0 && e == 0 && f == 0 && math.Abs(b/d) != 1:
			{
				fmt.Print(0)
			}
		case equal(a, c, b, d) && c != 0 && f != 0 && a/c != e/f:
			{
				fmt.Print(0)
			}
		case equal(a, c, b, d) && c != 0 && e == 0 && f == 0 && math.Abs(a/c) != 1:
			{
				fmt.Print(0)
			}
		case a == 0 && c == 0 && d != 0:
			{
				if b*(f/d) == e {
					fmt.Printf("4 %.5f", f/d)
				} else {
					fmt.Print(0)
				}
			}
		case a == 0 && c == 0 && b != 0:
			{
				if d*(e/b) == f {
					fmt.Printf("4 %.5f", e/b)
				} else {
					fmt.Print(0)
				}
			}
		case b == 0 && d == 0 && c != 0:
			{
				if a*(f/c) == e {
					fmt.Printf("3 %.5f", f/c)
				} else {
					fmt.Print(0)
				}
			}
		case b == 0 && d == 0 && a != 0:
			{
				if c*(e/a) == f {
					fmt.Printf("3 %.5f", e/a)
				} else {
					fmt.Print(0)
				}
			}
		case c != 0 && d != 0 && f != 0 && a/c == b/d && b/d == e/f:
			{
				fmt.Printf("1 %.5f %.5f", -c/d, f/d)
			}
		case a != 0 && b != 0 && e != 0 && c/a == d/b && d/b == f/e:
			{
				fmt.Printf("1 %.5f %.5f", -a/b, e/b)
			}
		case c != 0 && d != 0 && f == 0 && e == 0 && a/c == b/d && math.Abs(b/d) == 1:
			{
				fmt.Printf("1 %.5f %.5f", -a/b, e/b)
			}
		case a != 0 && b != 0 && f == 0 && e == 0 && c/a == d/b && math.Abs(d/b) == 1:
			{
				fmt.Printf("1 %.5f %.5f", -a/b, e/b)
			}
		}
	}
}