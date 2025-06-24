package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Density1 returns the sum of the largest grouping in slice `nums`.
// Groupings are determined by adjacent non-zero numbers.
// If two or more groups share length, greater sum is chosen.
func Density1(nums []int) int {
	maxLen, maxSum := 0, 0
	currLen, currSum := 0, 0

	for _, num := range nums {
		if num != 0 {
			currLen++
			currSum += num
		} else {
			if currLen > maxLen || (currLen == maxLen && currSum > maxSum) {
				maxLen, maxSum = currLen, currSum
			}

			currSum, currLen = 0, 0
		}
	}
	if currLen > maxLen || (currLen == maxLen && currSum > maxSum) {
		maxSum = currSum
	}

	return maxSum
}

func main() {
	s := bufio.NewScanner(os.Stdin)

	nums := []int{}

	s.Scan()
	s.Scan()

	line := s.Text()
	fields := strings.Fields(line)

	for _, f := range fields {
		num, _ := strconv.Atoi(f)
		nums = append(nums, num)
	}

	fmt.Print(Density1(nums))
}
