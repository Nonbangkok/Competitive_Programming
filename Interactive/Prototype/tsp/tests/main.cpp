#include "tsp.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int score = 0;
    vector<pair<vector<vector<int>>, int>> tests = {
        {{{0, 1, 15, 6}, {2, 0, 7, 3}, {9, 6, 0, 12}, {10, 4, 8, 0}}, 21},
        {{{0, 10, 15, 20}, {5, 0, 9, 10}, {6, 13, 0, 12}, {8, 8, 9, 0}}, 35},
        {{{0, 29, 20}, {29, 0, 15}, {20, 15, 0}}, 64}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        int result = tsp(tests[i].first);
        if (result == tests[i].second) {
            cout << "Test " << i + 1 << " ✅ (+10 คะแนน)\n";
            score += 10;
        } else {
            cout << "Test " << i + 1 << " ❌ (คาดหวัง: " << tests[i].second << ", ได้: " << result << ")\n";
        }
    }

    cout << "\n🎯 คะแนนรวม: " << score << " / 30\n";
    return 0;
}