#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    ll t;
    cin >> t;
    while(t--){
        ll n,a[3];
        cin >> n >> a[0] >> a[1] >> a[2];

        ll d = n/(a[0]+a[1]+a[2]);
        n -= d*(a[0]+a[1]+a[2]);
        d *= 3;
        while(n>0){
            n-= a[d%3];
            d++;
        }
        cout << d << endll;
    }

    return 0;
}