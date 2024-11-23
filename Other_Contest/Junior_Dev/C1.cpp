#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main(){macos;

    ull n;
    cin >> n;

    int leadingZeros = __builtin_clzll(n);
    ull highestBit;
    if (leadingZeros == 0) {
        highestBit = 0ULL;
    } else {
        highestBit = 1ULL << (64 - leadingZeros);
    }

    cout << 2 * n - highestBit + 1;
    return 0;
}