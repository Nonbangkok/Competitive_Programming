#include "fibonacci.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int score = 0;

    vector<pair<int, int>> testCases = {
        {0, 0}, {1, 1}, {2, 1}, {3, 2}, {4, 3},
        {5, 5}, {6, 8}, {7, 13}, {8, 21}, {10, 55}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        int n = testCases[i].first;
        int expected = testCases[i].second;
        int result = fibonacci(n);
        if (result == expected) {
            cout << "Test " << i + 1 << " ✅ (+10 points)\n";
            score += 10;
        } else {
            cout << "Test " << i + 1 << " ❌ (Expected : " << expected << ", Given : " << result << ")\n";
        }
    }

    cout << "\n🎯 Total Score : " << score << " / 100\n";
    return 0;
}