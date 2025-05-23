#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Finds sum of numbers in the longest group, if longest group count is more than one, finds maximum sum value.
 * 1 0 4 1 2 4 0 0 3 1 1 1
 * There is 3 groups; 1 | 4 1 2 4 | 3 1 1 1. Longest group length is 4, there are two longest group.
 * Sums of longest groups are 11 and 6. So, we return 11.
 * 
 * @param nums 
 * @return long long 
 */
long long find_max_longest_consuctive_numbers(vector<long long> nums) {
    // count represents count of numbers in current group, sum represents sum of numbers in current group.
    long long currentCount = 0, maxCount = 0, sum = 0, maxSum = 0;

    for (long long num : nums) {
        if (num != 0) { 
            currentCount++;
            sum += num;
        } else {
            if (currentCount >= maxCount) {
                if (currentCount > maxCount || sum > maxSum) {
                    maxCount = currentCount;
                    maxSum = sum;
                }
            }

            currentCount = 0, sum = 0;
        }
    }

    // Works when there is no 0 at the end of the array.
    if (currentCount >= maxCount) {
        if (currentCount > maxCount || sum > maxSum) {
            return sum;
        }
    }

    return sum;
}


int main(void) {
    vector<long long> nums = {2, 0, 1, 1, 1, 0, 0, 4, 2, 3}; 
    const long long result = find_max_longest_consuctive_numbers(nums);

    cout << result << endl;
    return 0;
}
