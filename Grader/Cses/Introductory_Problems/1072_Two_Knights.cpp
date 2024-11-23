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

    ll k;
    cin >> k;
    for(ll i=1;i<=k;i++){
        ll total = (i*i)*(i*i-1)/2;
        ll attacked = 4*(i-1)*(i-2);
        cout << total-attacked << endll;
    }

    return 0;
}