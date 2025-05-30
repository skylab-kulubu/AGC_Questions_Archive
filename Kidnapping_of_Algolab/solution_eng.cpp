#include <iostream>
#include <iterator>
#include <ostream>
#include <set>
/**
    * @brief AGC Question 4
    * This function simulates a game where people are eliminated based on bullets.
    * The bullets are represented as an array, where 0 means the bullet is not used and 1 means it is used.
    * The function iterates through the people and bullets, eliminating people based on the bullets used.
    * The last person remaining is printed.
    * 
    * @param bullet_count: number of bullets
    * @param bullets: array of bullets, 0 means not used, 1 means used
    * @param people_count: number of people
    * @param [out] people: set of people, each person is represented by an integer from 1 to N called by reference so that it can be modified directly
 */
void elimination(int bullet_count, int bullets[], long int people_count, std::set<int> &people){
    int i = 0, j=0; 
    auto it = people.begin();

    // final: O(N)
    for(int k = 0; k < people_count; k++) { // O(N)
        people.insert(it, k + 1); // insert(pos, value) is amortized constant, ~O(1)
        std::advance(it, 1); // advance(it, n) is O(n) but n = 1, so it is O(1)
    }

    it = people.begin();

    // final: O(N)
    while (people.size() > 1) { // O(N)
        if (it == people.end()) {
            it = people.begin();
        }

        i = i % bullet_count;

        if(bullets[i] == 0) {
            bullets[i] = 1;
            std::advance(it, 1); // O(N) but N = 1, O(1)
        } else {
            bullets[i] = 0;

            auto next_iterator = std::next(it); // std::advance(it, 1) but returns new it, also O(1)
            people.erase(it); // amortized constant, ~O(1)
            it = next_iterator;
        }

        i++;
    }
}

int main() {
    std::set<int> people;

    int bullet_count;
    std::cin >> bullet_count; 

    int bullets[bullet_count];
    for(int i = 0; i < bullet_count; i++){
        std::cin >> bullets[i];
    }

    long int people_count;
    std::cin >> people_count;
 
    elimination(bullet_count, bullets, people_count, people);
    std::cout << *(people.begin()) << std::endl;
}
