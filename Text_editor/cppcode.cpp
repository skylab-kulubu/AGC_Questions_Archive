#include <bits/stdc++.h>    
using namespace std;
int hata = 0;
//1- iki sesli yan yana gelemez
//2- bir cümle max 4 kelime olabilir
//3- bir kelime max 7 harf olabilir
//4- toplam 30 kelime geçilmemeli
vector<string> tokenize(const string &str, const string &delimiters) {
    vector<string> tokens;
    size_t start = 0, end;

    while ((end = str.find_first_of(delimiters, start)) != string::npos) {
        if (end != start) {
            tokens.push_back(str.substr(start, end - start));
        }
        start = end + 1;
    }
    if (start < str.size()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

void vowelfunc(string str){
  
   vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < str.length(); i++)
    {
      int j=i+1;
      auto it1 = find(vowels.begin(), vowels.end(), str[i]);
      auto it2 = find(vowels.begin(), vowels.end(), str[j]);
      if(it1 != vowels.end() && it2 != vowels.end()) {
        ++hata;
      }
    }
    
}



int main(){
    int wordcnt =0;
    int totalwordcnt=0;
    string test = "baris kaan nilay algolab. seçim ucube kaan reis.";
    vowelfunc(test); 
    vector<string>vec2; // kelimelerin tutulacağı vector
    vector<string> vec = tokenize(test, "."); // cümlelerin tutulacağı vector
     for(string s: vec){
        
        //cout<< s <<endl; // cümleler yazdırılır

    }
   // cout << " ---------------------------------------" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
      wordcnt=0;
    vec2 = tokenize(vec[i]," ");  // cümlenin içindeki her bir kelime vec2ye atılır
      for(string s: vec2){
        //cout<< s <<endl;
        wordcnt++;
        if(s.length()>7){
            hata++;
        }
        totalwordcnt++;
    }
    if(wordcnt>4){
        hata++;
    }
    }
     if(totalwordcnt>30){
        hata++;
     }
     cout << hata;


    return 0;
}
