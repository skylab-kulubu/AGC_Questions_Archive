#include <iostream>

using namespace std;

/**
 * @brief Get the count of consecutive numbers group count
 * 
 * @param value The number will be sum of a consuctive number group.
 * @return int
 */
int get_count_of_groups(int value) {
    if (value == 1) return 0;

    int count = 0;
    int i = 2;

    /**
     * @brief Iterates subtracting the sum of 1..i from value and checking if it is divisible by i.
     * 
     * 1) 1..i is writable as sum of `i` numbers.
     * 2) "(value - (1..i)) is writable as `i` numbers" statement should be approved.
     * If a number is divisible by `i`, it can be written as `i` numbers.
     * 
     * For example, if value is 15:
     * i = 2 | (15 - (1 + 2)) % 2 = 0, count += 1
     * i = 3 | (15 - (3 + 3)) % 3 = 0, count += 1
     * i = 4 | (15 - (6 + 4)) % 4 = 1, continue
     * i = 5 | (15 - (10 + 5)) % 5 = 0, count += 1
     * i = 6, it breaks.
     */
    while (value >= (i * (i + 1) / 2)) {
        if((value - (i * (i + 1) / 2)) % i == 0) { 
            count++;
        }

        i++;
    }

    return count;
}

int main() {
    int value;
    cin >> value;

    const int count = get_count_of_groups(value);
    cout << count << endl;
    return 0;
}