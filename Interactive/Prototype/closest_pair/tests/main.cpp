#include "closest_pair.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int score = 0;
    vector<pair<vector<Point>, int>> tests = {
        {{{0,0},{1,0}}, 1},
        {{{0,0},{3,4}}, 7},
        {{{1,1},{4,1},{1,4}}, 3},
        {{{1,2},{4,6},{7,8},{10,12}}, 5},
        {{{1,1},{2,2},{3,3},{4,4}}, 2},
        {{{0,0},{5,5},{3,4}}, 2},
        {{{10,10},{15,15},{20,20}}, 10},
        {{{0,0},{0,3},{4,0}}, 4},
        {{{5,5},{5,10},{5,15}}, 5},
        {{{1,3},{2,2},{3,1},{4,0}}, 2}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        int result = closest_pair(tests[i].first);
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