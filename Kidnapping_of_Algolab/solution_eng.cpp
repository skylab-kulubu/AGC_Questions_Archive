#include <iostream>
#include <bits/stdc++.h> // Includes all standard template libraries
using namespace std;
using namespace std::chrono;

int main() {
    // Input: Bullet positions, number of chambers, number of people.
    // Output: Which person is the last one remaining?

    // Start measuring execution time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int n = 6; // Number of bullet chambers
    int bullets[n] = {0, 1, 1, 1, 0, 0}; // 0 = empty, 1 = loaded

    long int numPeople = 10; // 10^4

    unordered_set<int> people; // Set to store active players
    for(int i = 0; i < numPeople; i++) {
        people.insert(i + 1); // Insert players numbered from 1 to numPeople
    }

    int i = 0, j = 0; // i = index for bullets array, j = index for people
    auto it = people.begin(); // Iterator for people set

    // Game continues until only one person remains
    while(people.size() > 1) {
        j %= people.size();         // Ensure j stays within the range of remaining people
        advance(it, j);             // Move iterator j steps forward
        i = i % n;                  // Cycle through the bullets array

        if(bullets[i] == 0) {
            bullets[i] = 1;         // If bullet is empty, make it loaded (player survives)
        } else {
            bullets[i] = 0;         // If bullet is loaded, fire and eliminate the player
            people.erase(it);       // Remove player from the game
            j--;                    // Adjust j because the player was removed
        }

        it = people.begin();        // Reset iterator after modification
        i++;                        // Move to the next bullet
        j++;                        // Move to the next player
    }

    // End measuring execution time
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n"; 
    cout << *(people.begin()) << endl; 
    cout << "hello"; // Test line

    return 0;

    // Note: A solution without extra space is possible, but more complex.
}

// Time complexity: roughly O(n^2)
