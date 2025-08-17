import random
import string


weights = [1] * 26
weights[6] = 9 # g
weights[17] = 8 # r
weights[7] = 6 # h
weights[9] = 6 # j


def solve(inp: str):
    words = inp.split()
    result = []
    for word in words:
        n = len(word)
        if n == 0:
            result.append('')
            continue

        dp = [[False] * n for _ in range(n)]
        start = 0
        max_len = 1

        for i in range(n):
            dp[i][i] = True

        for i in range(n-1):
            if word[i] == word[i+1]:
                dp[i][i+1] = True
                start = i
                max_len = 2

        for length in range(3, n+1):
            for i in range(n - length + 1):
                j = i + length - 1
                if word[i] == word[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    start = i
                    max_len = length

        result.append(word[start:start + max_len])
    return max(result, key=len)


def generate_palindrome(lower: int, upper: int):
    n = random.randint(lower, upper)
    mid = (n + 1) // 2
    palindrome = random.choices(string.ascii_lowercase, weights, k=mid)
    palindrome += palindrome[::-1] * ~(mid % 2) + (mid % 2) * palindrome[-2::-1]
    return palindrome


# palindromes_list_short = []
# for _ in range(26):
#     palindromes_list_short.append(generate_palindrome(1, 5))
# palindromes_list_short += list(string.ascii_lowercase)
#
# palindromes_list_medium = []
# for _ in range(26):
#     palindromes_list_medium.append(generate_palindrome(6, 20))
# palindromes_list_medium += list(string.ascii_lowercase)
#
# palindromes_list_long = []
# for _ in range(26):
#     palindromes_list_long.append(generate_palindrome(21, 50))
# palindromes_list_long += list(string.ascii_lowercase)

ultra_long_palindrome = []
for _ in range(26):
    ultra_long_palindrome.append(generate_palindrome(9000, 9000))

long = random.choice(ultra_long_palindrome)
print(long)
print(solve(long))

# print(f'short: {palindromes_list_short}\nmedium: {palindromes_list_medium}\nlong: {palindromes_list_long}')
# st = ''
# word = st.join(random.choices(palindromes_list_short, k=5))
# print(word)


def generate_test_cases() -> None:
    # test_cases = [[] * 15 for _ in range(15)]
    test_cases = []

    for i in range(5):
        # test_cases[i].append(random.randint(1, 10))
        count = random.randint(1, 10)

        test_cases.append(case := [''.join(random.choices(palindromes_list_short, k=5)) for _ in range(count)])
        test_cases[i] = ' '.join(case)
        # test_cases.append([' '.join(random.choices(palindromes_list_short, k=5)) for _ in range(random.randint(1, 10))])

    for i in range(5, 10):
        # test_cases[i].append(random.randint(10, 25))
        count = random.randint(10, 25)
        test_cases.append(case := [''.join(random.choices(palindromes_list_medium, k=5)) for _ in range(count)])
        test_cases[i] = ' '.join(case)
        # test_cases.append([' '.join(random.choices(palindromes_list_medium, k=5)) for _ in range(random.randint(10, 25))])

    for i in range(10, 15):
        # test_cases[i].append(random.randint(25, 50))
        count = random.randint(25, 50)
        test_cases.append(case := [''.join(random.choices(palindromes_list_long, k=5)) for _ in range(count)])
        test_cases[i] = ' '.join(case)
        # test_cases.append([' '.join(random.choices(palindromes_list_long, k=5)) for _ in range(random.randint(25, 50))])

    print(f'test cases: {test_cases}')

    for index, val in enumerate(test_cases):
        with open('input' + str(index) + '.txt', 'w') as file:
            # file.write(str(val[0]))
            # file.write('\n')
            for i in val:
                file.write(str(i))
            file.write(' ')

        with open('output' + str(index) + '.txt', 'w') as file:
            out = solve(val)
            for i in out:
                file.write(str(i))
                # file.write(' ')


# inp = 'ycvoon ssizzimsscc iccvvaylfly abbbbaflnnl vvbkkbnrx vvtccst gggznrnzjjcc ccbaabntb roloryltvv'
# print(solve(inp))
# generate_test_cases()
