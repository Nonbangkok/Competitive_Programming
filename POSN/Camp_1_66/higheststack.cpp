#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    long long n,b = 0,i = 1;
    cin >> n;

    while (n >= 0)
    {
        n -= i;
        i++;
        b++;
    }
    cout << b-1;

    return 0;
 }
