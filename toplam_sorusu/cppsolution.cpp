#include <iostream>
//15  =  7+8; 1+2+3+4+5    yani 15=2
using namespace std;
// test case denemek laızm
int main(){

int count=0;
int num;
cin >> num;

int i = 2;
if(num == 1){
    cout << "0" << endl;
    return 0;
}

while (num >= i*(i+1)/2)
{
if((num-i*(i+1)/2)%i == 0){   // num == 45 i= 2      123456789    22 23     5678910    141516     7891011 
    count++;
                    
}
i++;
}

// i = 3 num = 1000000000  


cout << count << endl;
    return 0;
}