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

    ll t,n,m,x,y;
    cin >> t;

    while(t--){
        cin >> n >> m >> x >> y;
        ll l = 0, mid, r = 1e12;
        while(l<r){
            mid = (l+r) >> 1;

            ll both = mid/(x*y);
            ll y_notx = mid/y-both;
            ll x_noty = mid/x-both;
            ll not_both = mid-y_notx-x_noty-both;

            if(not_both<max(0LL,n-y_notx)+max(0LL,m-x_noty))l = mid + 1;
            else r = mid;
        }
        cout << l << endll;
    }

    return 0;
}