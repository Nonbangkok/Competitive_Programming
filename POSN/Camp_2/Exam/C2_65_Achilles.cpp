#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
set<ll> s;
int main() {macos;

    ll l,r;
    cin >> l >> r;

    for(ll i=1;i<=sqrt(r);i++){
        ll A=i*i;
        for(ll j=1;j<=300;j++){
            ll B=j*j*j;
            if(A*B>r)break;
            if(A*B>=l)s.insert(A*B);
        }
    }

    for(ll i=1;i<=sqrt(r);i++){
        ll sum=i;
        for(int j=1;j<=100;j++){
            sum*=i;
            if(sum>r)break;
            s.erase(sum);
        }
    }
    cout << s.size();

    return 0;
}