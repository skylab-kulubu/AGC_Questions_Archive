#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Sadece boşluklara göre split fonksiyonu
vector<string> split(const string& str) {
    vector<string> tokens;   // Token'ları saklayacağımız vector
    
    stringstream inputStream(str); // inputStream adında bir stringstream nesnesi oluşturduk
    
    string token;
    while (inputStream >> token) {  // inputStream üzerinden boşluklarla ayırarak her kelimeyi okur
        tokens.push_back(token);  // Token'ı vector'a ekler
    }
    return tokens;   // Sonuç olarak vector'ü döndürür
}

// Palindromik substring bulan fonksiyon
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

        // Tek karakterli tüm alt dizeler palindromiktir
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // İki karakterli palindromlar
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Daha uzun palindromlar
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

    // Kullanıcıdan string al
    cout << "Bir metin giriniz: ";
    getline(cin, input);

    // Stringi boşluklara göre parçala
    vector<string> inputs = split(input);

    // Parçalanan stringler üzerinde findPasswords çalıştır
    vector<string> passwords = findPasswords(inputs);

    // Sonuçları yazdır
    cout << "Gizlenmiş parolalar: " << endl;
    for (const string& password : passwords) {
        cout << password << endl;
    }

    return 0;
}
