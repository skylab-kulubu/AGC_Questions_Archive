#include <iostream>
#include <bits/stdc++.h> // STL kütüphanelerini içe aktarır

using namespace std;
using namespace std::chrono;
int main(){
    //input: Mermilerin yeri, yuva sayısı, kişi sayısı. output: En son kaçıncı kişi kalır?
    std::chrono::time_point<std::chrono::system_clock> start, end;// Süre ölçümü başlatılır
 
    start = std::chrono::system_clock::now();

    int n = 6; // mermi sayısı (mermi dizisinin boyutu)
    int bullets[n] =  {0,1,1,1,0,0};// 0 = boş, 1 = dolu mermi
    
    long int numPeople = 10; // 10^4
    
    unordered_set<int> people; 
    for(int i=0; i<numPeople; i++){
        people.insert(i+1);// kişileri 1'den başlayarak kümede sakla
    }
    
    
    int i = 0, j=0; // i bullets arrayinde geziniyor 
    auto it = people.begin();
    while(people.size()>1){
        j %= people.size(); // insan arrayi içinde geziniyor 0 0 0 0 0
        advance(it,j); // it = it+j   
        i = i % n; // merminin kaçıncı kişiye denk geleceğini hesaplıyoruz
        if(bullets[i]==0){
            bullets[i]=1;  // boş mermi → dolu yapılır (tetik çekildi, ama kişi hayatta)
        } else {
            bullets[i]=0; // dolu mermi → boş yapılır (tetik çekildi, kişi elendi)
            people.erase(it); // kişi oyundan çıkarılır
            j--;
        }
        it = people.begin();// küme silme sonrası iterator sıfırlanır
        i++;  // bir sonraki mermiye geç
        j++;  // bir sonraki kişiye geç
    }
    end = std::chrono::system_clock::now(); //süre ölçümü bitirilir
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    cout <<*(people.begin()) << endl;
    cout << "hello"; //test satırı

    return 0;
    //extra space'siz soru->yazılabilir ama zor olur
}


//Zaman karmaşıklığı: O(n^2) 
