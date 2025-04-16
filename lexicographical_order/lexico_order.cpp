#include <bits/stdc++.h>
using namespace std;
//lexicographical order
void lexicalOrder(int n) {
    vector<int>normal;
        for(int i=0; i<n; ++i){
            normal.push_back(i+1);
        }
    vector<string>lexical;
        for(int i=0; i<n; ++i){
            string str= to_string(normal[i]);
            lexical.push_back(str);
        }

    sort(lexical.begin(), lexical.end());

      for(int i=0; i<n; ++i){
        cout<< lexical[i]<< " ";
    }   
    }

int main()
{
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        lexicalOrder(n);
    }
    
    return 0;
}
