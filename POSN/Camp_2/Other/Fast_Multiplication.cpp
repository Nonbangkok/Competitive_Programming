#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const ll M = 1000000000000000003;

ll multiply(ll a,ll b){
    ll res = 0;
    while(b){
        if(b&1)res = (res + a) % M;
        a = ( a << 1) % M;
        b >>= 1;
    }
    return res;
}

int main(){macos;

    ll a,b;
    cin >> a >> b;
    cout << multiply(a,b);

    return 0;
}