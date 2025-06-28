#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/**
 * @brief Splits a string using " " delimeter.
 * For example, converts "a unsplitted string" to ["a", "unsplitted", "string"]
 * 
 * @param str 
 * @return vector<string> 
 */
vector<string> split(const string& str) {
    vector<string> tokens;

    // inputStream is a stream splitted by " ". For "a unsplitted string", it is ["a", "unsplitted", "string"] but not an array. It is stream so need to be
    // selected using stream get operator (>>)
    stringstream inputStream(str);

    string token;
    while (inputStream >> token) { // consumes stream until it ends
        tokens.push_back(token);
    }

    return tokens;
}

/**
 * @brief Creates a dynamic programming matrix to define word is palindrome or not.
 * For example;
 * dp[1][4] means that xbaabydfq, "baab" is a palindrome word from str[1] to str[4].
 * 
 * @param inputs Includes strings that are not includes " " character.
 * @return vector<string> 
 */
vector<string> findPasswords(const vector<string>& inputs) {
    vector<string> results;

    for (const string& s : inputs) {
        int n = s.length();
        if (n == 0) {
            results.push_back("");
            continue;
        }

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLength = 1;

        // All single sized strings are palindromic
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Checks two-sized strings are palindromic or not.
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // For longer than two strings
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = length;
                }
            }
        }

        results.push_back(s.substr(start, maxLength));
    }

    return results;
}

int main() {
    string input;

    cout << "Write the text to search passwords: ";
    getline(cin, input);

    vector<string> inputs = split(input);
    vector<string> passwords = findPasswords(inputs);

    cout << "Hidden passwords: " << endl;
    for (const string& password : passwords) {
        cout << password << endl;
    }

    return 0;
}
