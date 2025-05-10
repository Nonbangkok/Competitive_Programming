#include "lis.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int score = 0;
    vector<pair<vector<int>, int>> tests = {
        {{}, 0},
        {{1}, 1},
        {{1, 2, 3, 4, 5}, 5},
        {{5, 4, 3, 2, 1}, 1},
        {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
        {{0, 1, 0, 3, 2, 3}, 4},
        {{7, 7, 7, 7, 7}, 1},
        {{1, 3, 6, 7, 9, 4, 10, 5, 6}, 6},
        {{2, 2}, 1},
        {{1, 2, 4, 3}, 3}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        int result = lis(tests[i].first);
        if (result == tests[i].second) {
            cout << "Test " << i+1 << " ✅ (+10 คะแนน)\n";
            score += 10;
        } else {
            cout << "Test " << i+1 << " ❌ (คาดหวัง: " << tests[i].second << ", ได้: " << result << ")\n";
        }
    }

    cout << "\n🎯 คะแนนรวม: " << score << " / 100\n";
    return 0;
}