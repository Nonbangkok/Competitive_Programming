#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const ll M = 998244353;

int main(){macos;

    int q;
    ll n,res,a,temp;
    cin >> q;

    while(q--){
        cin >> n;
        temp = n%M;
        res = 1LL;
        a = 2LL;
        while(n){
            if(n&1)res = (res * a) % M;
            a = (a * a) % M;
            n >>= 1;
        }
        cout << (res-temp+M)%M << endll;
    }

    return 0;
}