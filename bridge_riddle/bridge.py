import heapq

# uses heap not to sort in O(n*lgn), instead heap +/- in O(lgn), heapify in O(n)


def bridge_riddle(nums: list[int]) -> int:
    # deep copy not to modify original nums, might be redundant
    people_l = nums.copy()
    people_r = []
    time = 0

    while len(people_l) > 3:
        # heap to get fast people quicker
        heapq.heapify(people_l)

        # get two fastest people from left, traverse them to right, increment elapsed time
        (fast_1 := heapq.heappop(people_l)), (fast_2 := heapq.heappop(people_l))
        time += max(fast_1, fast_2)
        heapq.heappush(people_r, fast_1)
        heapq.heappush(people_r, fast_2)

        # get fastest of right side, traverse them to left, increment elapsed time
        time += (right_fastest := heapq.heappop(people_r))
        heapq.heappush(people_l, right_fastest)

        # max heap to get slowest people fast
        heapq._heapify_max(people_l)

        # get two slowest people from left, traverse them to right, increment elapsed time
        (slow_1 := heapq._heappop_max(people_l)), (slow_2 := heapq._heappop_max(people_l))
        time += max(slow_1, slow_2)
        heapq.heappush(people_r, slow_1)
        heapq.heappush(people_r, slow_2)

        # get the remaining fast person, traverse them to the left, increment elapsed time
        (fast := heapq.heappop(people_r))
        time += fast
        heapq.heappush(people_l, fast)

    # increment the final time elapsed for remaining people:
    # sum of all if 3 is left, slowest of the two if 2 is left
    time += (sum(person for person in people_l) if len(people_l) == 3 else max(people_l))

    return time


def main() -> None:
    nums = [1, 4, 2, 5, 3]
    nums1 = [1, 2, 5, 10]
    nums2 = [1, 1, 1, 1, 1, 2]
    assert bridge_riddle(nums) == 16
    assert bridge_riddle(nums1) == 17
    assert bridge_riddle(nums2) == 10


if __name__ == '__main__':
    main()
