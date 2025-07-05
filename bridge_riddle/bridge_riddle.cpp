#include <iostream>
#include <list>
#include <cassert>
#include <algorithm>
#include <numeric>

/*
*@brief 
* finds and returns the shortest time possible for everyone to cross the bridge 
* using the data people_l and moving them to people_r(function variable)
*@param people_l list that hold the values (time taken for each person to pass the bridge)
*@return time the found value 
*/
std::size_t bridge_riddle(std::list<std::size_t>& people_l) {
    people_l.sort();

    std::list<std::size_t> people_r{};

    std::size_t time{0};
/** Itarates through people_l and people_r to keep the torch going and making people cross the bridge
 * The strategy involves:
 * 1. Sending the two fastest across. (for a quick start)
 * 2. Returning the torch with the faster of those two. (for a quick return)
 * 3. Sending the two slowest across. (They go at the slowest person's speed.This clears the two slowest person, making sure not to extend the time in future crossings)
 * 4. Returning the torch with the fastest person from the right side. (for a quick return)
 * This cycle repeats until only three or fewer people remain.
 */
/**
 * WHY Less than 3 PEOPLE?
 * Because when there is three people left no matter the times it always adds up tu the sum of each.
 * Example: 
 * 1 2 3 (1 and 2 goes (+2) 1 comes back (+1) 1 and 3 goes (+3))
 * And if there are two left the answer is the longer time taken
 * 
*/

/**
 * An example solution when people_l = {1,5,12,18,25}
 * outgoing  total time     people_l       people_r
 * 1 5       +5             12 18 25       1 5
 * 1         +1             1 12 18 25     5
 * 18 25     +25            1 12           5 18 25
 * 5         +5             1 5 12         18 25
 * 1 5       +5             12             1 5 18 25
 * 1         +1             1 12           5 18 25
 * 1 12      +12            ...            1 5 12 18 25
 * answer :   54 sec
 */
    while (people_l.size() > 3) {
        // get fastest two people from the front, traverse them to right and update time
        std::size_t fast_1{ people_l.front() };
        people_l.pop_front();
        std::size_t fast_2{ people_l.front() };
        people_l.pop_front();

        time += std::max(fast_1, fast_2);

        people_r.insert(people_r.begin(), { fast_2, fast_1 });

        // return the faster one to left and update time
        std::size_t fast_r{ people_r.front() };
        people_r.pop_front();
        time += fast_r;

        people_l.push_front(fast_r);

        // get slowest two people from the back, traverse them to right and update time
        std::size_t slow_1{ people_l.back() };
        people_l.pop_back();
        std::size_t slow_2{ people_l.back() };
        people_l.pop_back();

        time += std::max(slow_1, slow_2);

        people_r.insert(people_r.end(), { slow_2, slow_1 });

        // get the remaining fast person from right, traverse them to left and update time
        std::size_t fast{ people_r.front() };
        people_r.pop_front();

        time += fast;
        
        people_l.push_front(fast);

        // in each iteration, slowest two people is traversed to right, continue until only three people left on left side
    }

    // update the time one last time and clear left side
    time += (people_l.size() == 3 ? std::accumulate(people_l.begin(), people_l.end(), 0) : *std::max_element(people_l.begin(), people_l.end()));

    return time;
}

int main() {
    std::size_t n{};
    std::cin >> n;

    std::list<std::size_t> people{};
    for (std::size_t i{}; i < n; ++i) {
        std::size_t elem{};
        std::cin >> elem;
        people.push_back(elem);
    }

    std::cout << bridge_riddle(people);

    return 0;
}
