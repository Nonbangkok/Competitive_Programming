#include "longest_path.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int score = 0;
    vector<pair<vector<vector<pair<int, int>>>, int>> tests = {
        {{{{1, 3}}, {{2, 4}}, {}}, 7},
        {{{{1, 2}, {2, 3}}, {{2, 5}}, {}}, 7},
        {{{}, {}, {}}, 0},
        {{{{1, 1}}, {{2, 1}}, {{3, 1}}, {}}, 3},
        {{{{1, 10}, {2, 5}}, {{3, 1}}, {{3, 100}}, {}}, 105}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        int result = longest_path(tests[i].first.size(), tests[i].first);
        if (result == tests[i].second) {
            cout << "Test " << i + 1 << " ✅ (+10 คะแนน)\n";
            score += 10;
        } else {
            cout << "Test " << i + 1 << " ❌ (คาดหวัง: " << tests[i].second << ", ได้: " << result << ")\n";
        }
    }
    cout << "\n🎯 คะแนนรวม: " << score << " / 50\n";
    return 0;
}