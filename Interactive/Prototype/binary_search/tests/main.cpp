#include <iostream>
#include <vector>
#include "bsearch.h"

using namespace std;

int main() {
    
    int total_score = 0;
    const int score_per_test = 10;

    auto check = [&](int test_id, int actual, int expected) {
        if (actual == expected) {
            total_score += score_per_test;
            cout << "Test " << test_id << " ✅ Passed | Total: " << total_score << endl;
        } else {
            cout << "Test " << test_id << " ❌ Failed (Expected " << expected << ", got " << actual << ") | Total: " << total_score << endl;
        }
    };

    // Tests
    check(1, binary_search({1, 2, 3, 4, 5}, 3), 2);
    check(2, binary_search({10, 20, 30, 40}, 10), 0);
    check(3, binary_search({10, 20, 30, 40}, 40), 3);

    check(4, binary_search({1, 2, 3, 4, 5}, 6), -1);
    check(5, binary_search({}, 1), -1);
    check(6, binary_search({100}, 50), -1);

    check(7, binary_search({5}, 5), 0);
    check(8, binary_search({5}, 3), -1);
    check(9, binary_search({1 , 5 , 7}, 3), -1);
    check(10, binary_search({1 , 2 , 3}, 3), 2);

    cout << "📊 Final Total Score: " << total_score << " / 100" << endl;

    return 0;
}
