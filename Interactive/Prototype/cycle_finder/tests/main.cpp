#include "cycle_finder.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int score = 0;
    vector<pair<int, vector<pair<int, int>>>> tests = {
        {3, {{0, 1}, {1, 2}}},               // No cycle
        {3, {{0, 1}, {1, 2}, {2, 0}}},       // Has cycle
        {4, {{0, 1}, {2, 3}}},               // No cycle
        {4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}}}, // Has cycle
        {5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}} // No cycle
    };
    vector<bool> expected = {false, true, false, true, false};

    for (size_t i = 0; i < tests.size(); ++i) {
        bool result = has_cycle(tests[i].first, tests[i].second);
        if (result == expected[i]) {
            cout << "Test " << i+1 << " ✅ (+10 คะแนน)\n";
            score += 10;
        } else {
            cout << "Test " << i+1 << " ❌ (คาดหวัง: " << expected[i] << ", ได้: " << result << ")\n";
        }
    }
    cout << "\n🎯 คะแนนรวม: " << score << " / 50\n";
    return 0;
}