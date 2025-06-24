# Density 1 python solution.

import random
import itertools


def density_i(lst: list[int]) -> int:
    current_count = 0
    subarray_sum = 0
    max_count = 0
    max_sum = 0
    for num in lst:
        if num != 0:
            current_count += 1
            subarray_sum += num
        else:
            if current_count >= max_count:
                if current_count > max_count or subarray_sum > max_sum:
                    max_count = current_count
                    max_sum = subarray_sum

            current_count, subarray_sum = 0, 0

    if current_count >= max_count:
        if current_count > max_count or subarray_sum > max_sum:
            max_sum = subarray_sum

    return max_sum


if __name__ == '__main__':
    arr = list(map(int, input().split()))
    print(density_i(arr))
