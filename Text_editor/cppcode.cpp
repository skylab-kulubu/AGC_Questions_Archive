#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int errors = 0;

/**
 * @brief Splits string using the delimiter, for example;
 * "i love you" and " " is {"i", "love", "you"}
 * 
 * @param str 
 * @param delimiters 
 * @return vector<string>
 */
vector<string> tokenize(const string &str, const string &delimiters) {
    vector<string> tokens;
    size_t start = 0, end;

    while ((end = str.find_first_of(delimiters, start)) != string::npos) {
        if (end != start) {
            tokens.push_back(str.substr(start, end - start));
        }

        start = (end + 1);
    }

    if (start < str.size()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

/**
 * @brief Counts vowel groups includes more than one vowel in the string as errors.
 * For example, add 2 to errors variable for "ateasdoea"
 * 
 * @param str 
 */
void vowelfunc(string str) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < str.length(); i++) {
      int j = (i + 1);
      auto it1 = find(vowels.begin(), vowels.end(), str[i]);
      auto it2 = find(vowels.begin(), vowels.end(), str[j]);

      if(it1 != vowels.end() && it2 != vowels.end()) {
        ++errors;
      }
    }    
}

/**
 * @brief Counts words includes more than 7 characters as errors and add 1 to totalwordcnt for each word.
 * 
 * @param words 
 * @param totalwordcnt 
 */
void check_words(vector<string> words, int *totalwordcnt) {
    for (string s : words) {
        if (s.length() > 7){
            errors++;
        }

        (*totalwordcnt)++;
    }
}

/**
 * @brief Counts all words in input and if word count is more than 30, it counts as a error.
 * Also, counts all words in each sentence and if word count in a sentence is more than 4, it counts as a error.
 * Finally, checks all words in a sentence using check_words() method.
 * 
 * @param input 
 */
void check_sentences(string input) {
    int totalwordcnt = 0;

    vector<string> sentences = tokenize(input, ".");
    vector<string> words; // temporary words vector for each sentence, resets on a new sentence

    for (int i = 0; i < sentences.size(); i++) {
        words = tokenize(sentences[i], " ");
        check_words(words, &totalwordcnt);

        if(words.size() > 4) {
            errors++;
        }
    }

    if (totalwordcnt > 30){
        errors++;
    }
}


int main() {
    string input;
    cin >> input; /**< input format should be "it is in asked questions repository of algolab. this question name is text editor." */

    vowelfunc(input);
    check_sentences(input);

    cout << errors;
    return 0;
}
