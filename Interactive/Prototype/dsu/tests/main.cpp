#include "dsu.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int score = 0;

    DSU dsu(10);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    if (dsu.same(1, 3)) { cout << "Test 1 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 1 ❌\n";

    if (!dsu.same(1, 4)) { cout << "Test 2 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 2 ❌\n";

    dsu.unite(4, 5);
    dsu.unite(5, 6);
    if (dsu.same(4, 6)) { cout << "Test 3 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 3 ❌\n";

    dsu.unite(3, 6);
    if (dsu.same(1, 6)) { cout << "Test 4 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 4 ❌\n";

    if (!dsu.same(0, 9)) { cout << "Test 5 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 5 ❌\n";

    dsu.unite(0, 9);
    if (dsu.same(0, 9)) { cout << "Test 6 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 6 ❌\n";

    dsu.unite(0, 1);
    if (dsu.same(9, 2)) { cout << "Test 7 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 7 ❌\n";

    if (dsu.same(9, 4)) { cout << "Test 8 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 8 ❌\n";

    if (!dsu.same(7, 8)) { cout << "Test 9 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 9 ❌\n";

    dsu.unite(7, 8);
    if (dsu.same(7, 8)) { cout << "Test 10 ✅ (+10 คะแนน)\n"; score += 10; }
    else cout << "Test 10 ❌\n";

    cout << "\n🎯 คะแนนรวม: " << score << " / 100\n";
    return 0;
}