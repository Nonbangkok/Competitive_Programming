#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int M = 1e9+7;

int main(){macos;

    ll q,n;
    cin >> q;
    while(q--){
        cin >> n;
        cout << (n-3)%M << endll;
    }

    return 0;
}