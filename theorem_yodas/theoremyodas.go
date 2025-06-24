package main

import (
	"fmt"
	"math"
)

// TheoremYodas returns the largest array `abcd` that equals a^2 + b^2 + c^2 + d^2 = sum
//
// First, stores a^2 + b^2 sums in a hashmap with a and b values going from 0 to square root of num, discarding duplicates.
// Then, again with values going from 0 to square root of num, checks if num - (c^2 + d^2) is present in the hashmap.
// Returns the largest array read from left to right.
func TheoremYodas(num int) (sum [4]int) {
	sums := map[int][2]int{}

	limit := int(math.Sqrt(float64(num)))
	for a := limit; a >= 0; a-- {
		for b := a; b >= 0; b-- {
			s := a*a + b*b
			if _, ok := sums[s]; s <= num && !ok {
				sums[s] = [2]int{a, b}
			}
		}
	}

	for c := 0; c <= limit; c++ {
		for d := 0; d <= c; d++ {
			if remainder := num - (c*c + d*d); remainder >= 0 {
				v, ok := sums[remainder]
				if ok {
					sum = [4]int{c, d, v[0], v[1]}
				}
			}
		}
	}

	return sum
}

func main() {
	var num int
	fmt.Scan(&num)

	fmt.Print(TheoremYodas(num))
}
