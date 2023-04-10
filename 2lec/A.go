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
		str        string
		s          []rune
		a          []int
        t          int 
		increasing    = true
	)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str = scanner.Text()
	s = []rune(str + " ")

	for i := 0; i < len(s); i++ {
		if unicode.IsDigit(s[i]) {
			k, _ := strconv.Atoi(string(s[i]))
			t += t*10 + k
		} else {
			a = append(a, t)
			t = 0
		}
	}

	for i := 1; i < len(a); i++ {
		if a[i-1] >= a[i] {
			increasing = false
		}
	}

	if increasing {
		fmt.Print("YES")
	} else {
		fmt.Print("NO")
	}
}
