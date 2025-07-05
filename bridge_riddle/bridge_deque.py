from collections import deque

# O(n*lgn + lgn) => O(n*lgn)
def bridge_riddle(people_l: list[int]) -> int:
  # O(n*lgn)
  people_l = deque(sorted(people_l))
  people_r = deque()

  time = 0

  # O(lgn) iteration
  while len(people_l) > 3:
    # Constant pop
    fast_1, fast_2 = people_l.popleft(), people_l.popleft()
    time += max(fast_1, fast_2)

    # Constant insert
    people_r.appendleft(fast_2)
    people_r.appendleft(fast_1)

    time += (fast_r := people_r.popleft())

    # Constant insert
    people_l.appendleft(fast_r)

    # Constant pop
    slow_1, slow_2 = people_l.pop(), people_l.pop()
    time += max(slow_1, slow_2)

    # Constant insert
    people_r.append(slow_2)
    people_r.append(slow_1)

    time += (fast := people_r.popleft())
    # Constant insert
    people_l.appendleft(fast)

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

