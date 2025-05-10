#include "inversion_count.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int score = 0;
    vector<pair<vector<int>, long long>> tests = {
        {{1, 2, 3, 4, 5}, 0},
        {{5, 4, 3, 2, 1}, 10},
        {{1, 3, 2, 3, 1}, 4},
        {{2, 4, 1, 3, 5}, 3},
        {{10, 9, 8, 7}, 6}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto arr = tests[i].first;
        long long expected = tests[i].second;
        long long result = count_inversions(arr);
        if (result == expected) {
            cout << "Test " << i+1 << " ✅ (+10 คะแนน)\n";
            score += 10;
        } else {
            cout << "Test " << i+1 << " ❌ (คาดหวัง: " << expected << ", ได้: " << result << ")\n";
        }
    }
    cout << "\n🎯 คะแนนรวม: " << score << " / 50\n";
    return 0;
}