from collections import deque

def bridge_riddle(people_l: list[int]) -> int:
  """Returns how much time is needed to have people cross to right side of the bridge.

  This involves a strategy that repeats the following steps until 3 persons are left on the left side:
  1) Send two fastest people.
  2) Have the faster of the pair return the torch.
  3) Send two slowest people.
  4) Have the remaining fast person return the torch.
  5) Repeat steps 1 through 4 until 3 people or less remain on the left.

  In each step, total time required is incremented based on the slowest person crossing.
  After having 3 or less people remained, their total pace is added to total time to finish.

  Summing 3 person's pace is a shortcut, instead, the loop might also be continued.

  >>> bridge_riddle([1, 4, 16])
  21

  >>> bridge_riddle([2, 1, 5, 10])
  17

  :param people_l: List of pace of every individual person that are on the left side on the bridge.

  :return: Total time needed for all to cross in the quickest way possible.
  """
  people_l = deque(sorted(people_l))
  people_r = deque()

  time = 0

  while len(people_l) > 3:
    fast_1, fast_2 = people_l.popleft(), people_l.popleft()
    time += max(fast_1, fast_2)

    people_r.appendleft(fast_2)
    people_r.appendleft(fast_1)

    time += (fast_r := people_r.popleft())

    people_l.appendleft(fast_r)

    slow_1, slow_2 = people_l.pop(), people_l.pop()
    time += max(slow_1, slow_2)

    people_r.append(slow_2)
    people_r.append(slow_1)

    time += (fast := people_r.popleft())
    people_l.appendleft(fast)

  time += (sum(person for person in people_l) if len(people_l) == 3 else max(people_l))
    
  return time


if __name__ == '__main__':
    input()
    people = list(map(int, input().split()))
    print(bridge_riddle(people))

