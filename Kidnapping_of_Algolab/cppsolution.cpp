#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
int main(){
    //input: Mermilerin yeri, yuva sayısı, kişi sayısı. output: En son kaçıncı kişi kalır?
    std::chrono::time_point<std::chrono::system_clock> start, end;
 
    start = std::chrono::system_clock::now();

    int n = 6; // mermi sayısı
    int bullets[n] =  {0,1,1,1,0,0};
    
    long int numPeople = 10; // 10^4
    
    unordered_set<int> people; 
    for(int i=0; i<numPeople; i++){
        people.insert(i+1);
    }
    
    
    int i = 0, j=0; // i bullets arrayinde geziniyor 
    auto it = people.begin();
    while(people.size()>1){
        j %= people.size(); // insan arrayi içinde geziniyor 0 0 0 0 0
        advance(it,j); // it = it+j   
        i = i % n; // merminin kaçıncı kişiye denk geleceğini hesaplıyoruz
        if(bullets[i]==0){
            bullets[i]=1;
        } else {
            bullets[i]=0;
            people.erase(it);
            j--;
        }
        it = people.begin();
        i++;
        j++;
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    cout <<*(people.begin()) << endl;
    cout << "hello";

    return 0;
    //extra space'siz soru->yazılabilir ama zor olur
}


//n^2 
