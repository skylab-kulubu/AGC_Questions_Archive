def find_passwords(inp: str) -> int:
    """Returns the longest palindrome in a single sentence.

    Sentence is split into its words and then, each palindrome in a string is found.
    Out of those, longest one's length is returned. A word can contain more that one palindromic substring.

    :param: sentence: Sentence string to be searched.
    :return: Length of the longest palindrome found in `sentence`.
    """
    words = inp.split()
    palindromes = []

    for word in words:
        n = len(word)
        if n == 0:
            palindromes.append('')
            continue

        # DP array that holds, for each word, the range of palindromic substrings.
        # dp[i][j] means word[i:j] is a palindrome.
        dp = [[False] * n for _ in range(n)]
        start = 0
        max_len = 1

        # Adding palindromes with length 1.
        for i in range(n):
            dp[i][i] = True
            start = i
        
        # Adding palindromes with length 2. 
        for i in range(n-1):
            if word[i] == word[i+1]:
                dp[i][i+1] = True
                start = i
                max_len = 2

        # Adding palindromes with length more than 2.
        for length in range(3, n+1):
            for i in range(n - length + 1):
                j = i + length - 1
                if word[i] == word[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    start = i
                    max_len = length
        palindromes.append(word[start:start + max_len])

    return len(max(palindromes, key=len))


def main():
    print(find_passwords(input()))

if __name__ == '__main__':
    main()