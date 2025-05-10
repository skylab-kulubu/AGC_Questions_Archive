# Density 1 python solution.

import random
import itertools


def fn(lst: list[int]) -> int:
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


def test_cases() -> None:
    weights = [10, 1, 1, 1, 1, 1, 1, 1, 1, 1]

    outputs = []
    
    for _ in range(5):
        with open('input'+str(_).zfill(2)+'.txt', 'w') as file:
            file.write(str(inp := random.choices(range(10), weights, k=random.randint(1, 101))).strip('[]').replace(',', ''))
            outputs.append(fn(inp))
    for _ in range(5, 10):
        with open('input'+str(_).zfill(2)+'.txt', 'w') as file:
            file.write(str(inp := random.choices(range(10), weights, k=random.randint(101, 10**3+1))).strip('[]').replace(',', ''))
            outputs.append(fn(inp))
    for _ in range(10, 15):
        with open('input'+str(_).zfill(2)+'.txt', 'w') as file:
            file.write(str(inp := random.choices(range(10), weights, k=random.randint(10**3+1, 10**6+1))).strip('[]').replace(',', ''))
            outputs.append(fn(inp))
    
    for index, output in enumerate(outputs):
        with open('output'+str(index).zfill(2)+'.txt', 'w') as file:
            file.write(str(output))

def main() -> None:
    # lst = [2, 0, 0, 1, 1, 1, 0, 0, 4, 2, 3]
    # lst2 = [4, 0, 7, 0, 0, 4, 0, 6, 9, 0, 1, 2, 0, 0, 0, 3, 1, 3, 3, 0, 8, 0, 4, 1, 0, 0, 0, 3, 0, 2, 6, 3, 0, 1, 0, 0]
    # print(fn(lst))
    test_cases()
    # print(fn(lst))


if __name__ == '__main__':
    main()
