def density_i(lst: list[int]) -> int:
    """Finds and returns the sum of the longest adjacent grouping in a list. Group with the larger
    sum is selected if there are more than one groups with the same length.

    >>> density_i([1, 1, 0, 2, 2])
    4

    :param lst: List of numbers to be searched.

    :return: Sum of the largest group.
    """
    current_count, subarray_sum, max_count, max_sum = 0

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
