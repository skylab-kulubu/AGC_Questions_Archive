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
            start = i

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
    return len(max(result, key=len))
    # return max_len


def main():
    print(solve(input()))


main()

# asadab badasa
