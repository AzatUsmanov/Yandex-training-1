package main

import "fmt"

func main() {
	var (
		troom, tcond int
		mode         string
	)
	fmt.Scan(&troom, &tcond)
	fmt.Scan(&mode)
	switch mode {
	case "freeze":
		if troom > tcond {
			troom = tcond
		}
	case "heat":
		if troom < tcond {
			troom = tcond
		}
	case "auto":
		troom = tcond
	}
	fmt.Print(troom)
}