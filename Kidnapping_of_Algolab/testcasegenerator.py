# n: mermi sayisi
# arr: mermi listesi
# int i: kontrol edilecek indis 
# int m: insan sayisi

# output bool

import random

import numpy
import numpy as np
import sys

from agc_cozum_py import agcsoru4


numpy.set_printoptions(threshold=sys.maxsize)

cases = []
"""
for _ in range(4):
    n = random.randint(1, int(10))
    m = random.randint(1, int(10))
    # arr = [random.randint(1, int(10e8)) for _ in range(n)]
    arr = np.random.randint(0, 2, n)
    # arr = ''.join(map(str, arr))
    i = random.randint(1, m+1)
    cases.append(list((n, arr, i, m)))
    # file.writelines(str)

for _ in range(4):
    n = random.randint(10, 100)
    m = random.randint(10, 100)
    # arr = [random.randint(1, int(10e8)) for _ in range(n)]
    arr = np.random.randint(0, 2, n)
    # arr = ''.join(map(str, arr))
    i = random.randint(1, m+1)
    cases.append(list((n, arr, i, m)))
    # file.writelines(str)
"""
for _ in range(4):
    n = random.randint(100, int(5E3))
    m = random.randint(100, int(5E3))
    # arr = [random.randint(1, int(10e8)) for _ in range(n)]
    arr = np.random.randint(0, 2, n)
    # arr = ''.join(map(str, arr))
    i = random.randint(1, m+1)
    cases.append(list((n, arr, i, m)))
    # file.writelines(str)

# print(*cases, sep='\n')

with open('test_cases.txt', 'w') as output:
    # output.write(str(cases))
    for line in cases:
        a, b, c, d = line
        output.write(str(a))
        output.write(' ')
        # output.write(str(b))
        for num in b:
            output.write(str(num))
        output.write(' ')

        output.write(str(c))
        output.write(' ')
        output.write(str(d))
        output.write(' ')
        output.write('\n')

with open('test_cases.txt', 'w') as file:
    for case in cases:
        a, b, c, d = case
        line = ' '.join([str(a), ','.join(str(b).strip('[]').replace(' ', '')), str(d)])
        file.write(line + '\n')