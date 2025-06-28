#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Writes numbers by string lexicographical order. For example;
 * lexicalOrder(12)
 * "1 10 11 12 2 3 4 5 6 7 8 9"
 * 
 * @param n 
 */
void lexicalOrder(int n) {
    vector<int> normal; // stores 1 to n numbers as int

    for(int i=0; i < n; ++i){
        normal.push_back(i+1);
    }

    vector<string> lexical;

    for(int i = 0; i < n; ++i){
        string str = to_string(normal[i]);
        lexical.push_back(str);
    }

    // sort() makes lexicographically orders for strings.
    sort(lexical.begin(), lexical.end());

    for(int i = 0; i < n; ++i) {
        cout << lexical[i] << " ";
    }
}

int main() {
    int q;
    cin >> q;

    // Makes lexical orders for Q numbers.
    while(q--){
        int n;
        cin >> n;
        lexicalOrder(n);
    }
    
    return 0;
}
