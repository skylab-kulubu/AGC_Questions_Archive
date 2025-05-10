//Verilen bir sayı dizisinde, sıfırdan farklı sayıların en sık (yani ardışık en uzun) olduğu kümede yer alan sayıların toplamı bulunmalıdır.
//Eğer bu uzunluğa sahip birden fazla küme varsa, toplamı büyük olan tercih edilmelidir.
// Sayıların büyüklüğünün sıklık ile bir alakası yok. Sadece 0 olup olmaması önemlidir.

#include <iostream>
#include <vector>

int main (void) {
    std::vector <long long> nums = {2, 0, 1, 1, 1, 0, 0, 4, 2, 3}; 
    long long currentCount = 0, maxCount = 0, sum = 0, maxSum = 0;

    for (long long num : nums) {
        if (num != 0) { 
            currentCount++; //ardışık sayı adedini arttırır
            sum += num; //toplama sayıyı ekleyerek toplamı güncelle
        }
        else { //Eğer sayı 0'a eşitse kontrol et
            if (currentCount >= maxCount) { //Şu anki ardışık sayı miktarı mevcut miktardan büyük mü diye kontrol et
                if (currentCount > maxCount || sum > maxSum) { //ardışık sayı miktarı büyükse veya eşitlik durumu için sayıların toplamı büyükse
                    maxCount = currentCount; //bulduğumuz sonucu yeni maksimum değer yap
                    maxSum = sum; //bulduğumuz toplamı yeni maksimum değer yap
                }
            }
            currentCount = 0, sum = 0; //sayaçları sıfırla
        }
    }

    // Array sonunda 0 yoksa döngüdeki else'e girmediği için son kontrol noktası
    if (currentCount >= maxCount) {
        if (currentCount > maxCount || sum > maxSum) {
            maxSum = sum;
        }
    }

    std::cout << maxSum << "\n"; // 1,1,1 ve 4,2,3 için uzunluk eşit bu yüzden toplamlarını karşılaştırırız ve sonuç4+2+3=9 olur

    return maxSum;
}
