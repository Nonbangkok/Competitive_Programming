#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,m=1e9+7;
    ll ans=1;
    cin >> n;
    while(n--)ans=(ans*2)%m;
    cout << ans;

    return 0;
}