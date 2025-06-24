package main

import (
	"fmt"
	"math"
)

// TheoremYodas returns the largest array `abcd` that equals a^2 + b^2 + c^2 + d^2 = sum
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

	for c := limit; c >= 0; c-- {
		for d := limit; d >= 0; d-- {
			if remainder := num - (c*c + d*d); remainder >= 0 {
				v, ok := sums[remainder]
				if ok {
					sum = [4]int{v[0], v[1], c, d}
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
