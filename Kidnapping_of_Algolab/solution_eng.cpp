#include <bits/stdc++.h>
/**
    * @brief AGC Sorusu 4
    * This function simulates a game where people are eliminated based on bullets.
    * The bullets are represented as an array, where 0 means the bullet is not used and 1 means it is used.
    * The function iterates through the people and bullets, eliminating people based on the bullets used.
    * The last person remaining is printed.
    * 
    * @param bulletcount: number of bullets
    * @param bullets: array of bullets, 0 means not used, 1 means used
    * @param Peoplecount: number of people
    * @param [out] people: set of people, each person is represented by an integer called by reference so that it can be modified directly
 */
void elimination(int bullet_count, int bullets[],long int people_count,unordered_set<int> &people){
    int i = 0, j=0; 
    auto it = people.begin();
    for(int k=0; k<people_count; k++){
        people.insert(k+1); 
    }
    while(people.size()>1){
        
        j %= people.size();
        
        std::advance(it,j);   

        i = i % bullet_count; 
        
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
}
int main() {
   
    std::unordered_set<int> people;

    int bullet_count;
    std::cin >> bullet_count; 

    int bullets[bullet_count];
    for(int i=0; i<bullet_count; i++){
        std::cin >> bullets[i];
    }

    long int people_count;
    std::cin >> people_count;
 
    elimination(bullet_count, bullets, people_count, people);
    
    std::cout << *(people.begin()) << std::endl;
}
