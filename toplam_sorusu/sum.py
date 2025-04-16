import random

def consecutive_sum(sum: int) -> int:
  """
  Returns the count of possible consecutive integer sums that add up to `sum` with different lengths.

  For some length `i`, it is implied there is a sum such that `x + x+1 + x+2 + ... + x+(i-1)` for some number `x` 
  with length `i` equals `sum`. Through simplifying the sum, equation becomes `i*x + (x*(x-1)/2) = sum`.
  If `sum - (x*(x-1)/2) % i = 0`, it implies the `x` is a natural number, so the count is incremented.

  >>> consecutive_sum(15)
  3

  Explanation for input `15`: 
  
  Sum #1 with length of `2`: `7 + 8`

  Sum #2 with length of `5`: `1 + 2 + 3 + 4 + 5`,

  Sum #3 with length of `3`: `4 + 5 + 6`, 
  """
  # num = int(input())
  count = 0

  i = 2;
  if sum == 1:
      print(0);

  while sum >= i*(i+1) / 2:
    if (sum - i*(i-1)/2) % i == 0:
      count += 1
      print(*((int((sum-(i*(i-1)/2))/i+x)) for x in range(i)))
    i += 1
  return count

if __name__ == '__main__':
  print(consecutive_sum(int(input())))


