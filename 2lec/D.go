package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"unicode"
)

func main() {
	var (
		str   string
		s     []rune
		a     []int
		minus bool
		t, k  int
	)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str = scanner.Text()
	s = []rune(str + " ")

	for i := 0; i < len(s); i++ {
		if unicode.IsDigit(s[i]) {
			k, _ := strconv.Atoi(string(s[i]))
			t = t*10 + k
		} else if s[i] == rune('-') {
			minus = true
		} else {
			if minus {
				t = t * (-1)
			}
			a = append(a, t)
			t = 0
			minus = false
		}
	}

	for i := 1; i < len(a)-1; i++ {
		if a[i-1] < a[i] && a[i] > a[i+1] {
			k++
		}
	}
	
	fmt.Print(k)
}
