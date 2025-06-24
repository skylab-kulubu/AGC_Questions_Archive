package main

import (
	"fmt"
)

// sum returns the count of possible consecutive integer sums that
// add up to `sum` with different lengths.
//
// The number itself is not considered a sum.
func sum(num int) (sumCount int) {
	if num == 1 {
		return 0
	}

	i := 2
	for num >= i*(i+1)/2 {
		if (num-i*(i-1)/2)%i == 0 {
			sumCount++
		}
		i++
	}

	return sumCount
}

func main() {
	var num int
	fmt.Scan(&num)

	fmt.Print(sum(num))
}
