package main

import (
	"fmt"
	"unicode"
)

func main() {
	var (
		bnum, num [4][]rune
		temp string
	)
	for i := 0; i < 4; i++ {
		fmt.Scan(&temp)
		bnum[i] = []rune(temp)
		for j := 0; j < len(bnum[i]); j++ {
			if unicode.IsDigit(bnum[i][j]) {
				num[i] = append(num[i], bnum[i][j])
			}
		}
		if len(num[i]) == 7 {
			num[i] = append([]rune("7495"), num[i]...)
		}
	}
	for i := 1; i < 4; i++ {
		if string(num[0][1:]) == string(num[i][1:]) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
