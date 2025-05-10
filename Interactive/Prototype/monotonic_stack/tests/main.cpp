#include "monotonic_stack.h"
#include <iostream>
#include <vector>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a == b;
}

int main() {
    int score = 0;
    vector<pair<vector<int>, vector<int>>> tests = {
        {{4, 5, 2, 10, 8}, {2, 2, -1, 8, -1}},
        {{1, 3, 0, 2, 5}, {0, 0, -1, -1, -1}},
        {{9, 8, 7, 6}, {8, 7, 6, -1}},
        {{1, 2, 3, 4}, {-1, -1, -1, -1}},
        {{5, 4, 3, 2, 1}, {4, 3, 2, 1, -1}}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto result = next_smaller_elements(tests[i].first);
        if (compare(result, tests[i].second)) {
            cout << "Test " << i + 1 << " ✅ (+10 คะแนน)\n";
            score += 10;
        } else {
            cout << "Test " << i + 1 << " ❌\n";
        }
    }

    cout << "\n🎯 คะแนนรวม: " << score << " / 50\n";
    return 0;
}