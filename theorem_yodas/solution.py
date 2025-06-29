from math import sqrt

def find(num: int):
  """
    Finds a equality for num = a^2 + b^2 + c^2 + d^2. If cannot find, result will be a = b = c = d = 0
    Its time complexity is O(N^2) because for loops starts from sqrt(num), not num.

    >>> find(12)
    [3, 1, 1, 1]

    :param num: The target number to find equality of a^2 + b^2 + c^2 + d^2
    :type num: int
    :return: 4-sized array of integers
  """
  value = int(sqrt(num))

  for i in range(value, -1, -1):
    for j in range(value, -1, -1):
      for k in range(value, -1, -1):
        for l in range(value, -1, -1):
          if (i * i + j * j + k * k + l * l) == num:
            return [i, j, k, l]

if "__main__" == __name__:
  num = int(input())
  res = find(num)

  print(f"{res[0]} {res[1]} {res[2]} {res[3]}")
