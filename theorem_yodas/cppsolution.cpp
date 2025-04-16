
#include <bits/stdc++.h>
// İÇ İÇE 4 FOR KULLAN KÖKn E KADAR GİDECEĞİ İÇİN O KÖKN^4 OLUYO = ON'2
// her sayı 4 ayrı doğal sayının karelerinin toplamı olarak yazılabilir
// BU SORUYU HARCAMA    0 100   soruyu ve outputu düzgün açıklamak gerekiyo    en büyük olanı  boşluk olmicak vs
using namespace std;
using namespace std::chrono;
/*void func(int number) {  
    int temp = number;
    vector<int> final(4,0);
    for(int i = 0; i < 4; ++i) {
        int sqrt_val = sqrt(temp);  
        final[i] = sqrt_val; 
        temp = temp - pow(sqrt_val, 2);
    }

   if(temp == 0){
        cout << final[0] << final[1] << final[2] << final[3]<<endl;
    }
    else{
              // 6 4 2 0
        final[0]--;      
        temp = number - pow( final[0], 2) ;
        for(int i = 1; i < 4; ++i) {
       int sqrt_val2 = sqrt(temp);
        final[i]= sqrt_val2;
        temp -= pow( sqrt_val2, 2);   , 
        
    }
     cout << final[0] << final[1] << final[2] << final[3] << endl;
    }
}*/

array<int, 4> func(int num) {
    array<int, 4> ans = {0, 0, 0, 0};
    int sqr = sqrt(num);
    for (int i = sqr; i >= 0; --i) {
        for (int j = sqr; j >= 0; --j) {
            for (int k = sqr; k >= 0; --k) {
                for (int l = sqr; l >= 0; --l) {
                    if (i * i + j * j + k * k + l * l == num) {
                        ans = {i, j, k, l};
                        return ans;
                    }
                }
            }
        }
    }
    return ans; // In case no combination is found
}


/*int main() {
     std::chrono::time_point<std::chrono::system_clock> start, end;
 
    start = std::chrono::system_clock::now();
    int number=195126;
    

    array<int, 4> result = func(number);

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << endl;
    return 0;
}*/

int main() {
    auto start = high_resolution_clock::now(); // Hassas zaman ölçümü
    
    int number = 96;
    array<int, 4> result = func(number);

    auto end = high_resolution_clock::now();
    duration<double> elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << endl;
   
    return 0;
}