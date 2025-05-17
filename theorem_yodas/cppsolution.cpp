#include <iostream>
#include <cmath>
#include <array>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * @brief Finds a equality for num = a^2 + b^2 + c^2 + d^2. If cannot find, result will be a = b = c = d = 0
 * Its time complexity is O(N^2) because for loops starts from sqrt(num), not sqrt(num).
 * 
 * @param num
 * @return array<int, 4> [a, b, c, d]
 */
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

    return ans;
}

int main() {
    // It gives sensitive time. We use this to calculate elapsed seconds.
    auto start = high_resolution_clock::now();

    int number;
    cin >> number;

    array<int, 4> result = func(number);

    auto end = high_resolution_clock::now();
    duration<double> elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << endl;
   
    return 0;
}
