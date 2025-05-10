//In a given sequence of numbers, the sum of the numbers in the set with the most frequent (i.e. longest consecutive) non-zero numbers must be found.
//If there is more than one set with this length, the one with the largest sum should be preferred.
//The size of the numbers has nothing to do with frequency. Only whether it is 0 or not is important.

#include <iostream>
#include <vector>

int main (void) {
    std::vector <long long> nums = {2, 0, 1, 1, 1, 0, 0, 4, 2, 3}; 
    long long currentCount = 0, maxCount = 0, sum = 0, maxSum = 0;

    for (long long num : nums) {
        if (num != 0) { 
            currentCount++; //increases the number of consecutive numbers
            sum += num; //update the sum by adding the number to the sum
        }
        else { //check if the number equals 0
            if (currentCount >= maxCount) { //check if current amount of consecutive numbers is greater than current amount
                if (currentCount > maxCount || sum > maxSum) { //if the amount of consecutive numbers is large or the sum of the numbers is large for equality
                    maxCount = currentCount; //make the result we found the new maximum value
                    maxSum = sum; //make the sum we found the new maximum value
                }
            }
            currentCount = 0, sum = 0; //reset counters
        }
    }

    // If there is no 0 at the end of the array, this is the last checkpoint since it does not enter the else in the loop.
    if (currentCount >= maxCount) {
        if (currentCount > maxCount || sum > maxSum) {
            maxSum = sum;
        }
    }

    std::cout << maxSum << "\n"; // The length for 1,1,1 and 4,2,3 is equal so we compare their sums and the result is 4+2+3=9
    return maxSum;
}
