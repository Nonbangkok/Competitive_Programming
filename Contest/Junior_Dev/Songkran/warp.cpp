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

    ll n,a1,d,q,a,b;
    cin >> n >> a1 >> d >> q;

    while(q--){
        cin >> a >> b;
        
        ll l = 1,r = n+1,m;
        while(l<r){
            m = (l+r) >> 1;
            if(a1+(m-1)*d<a)l = m + 1;
            else r = m;
        }
        a = l;

        l = 1,r = n+1;
        while(l<r){
            m = (l+r) >> 1;
            if(a1+(m-1)*d<=b)l = m + 1;
            else r = m;
        }
        b = l-1;
        
        cout << (b-a+1) * ((a1+(a-1)*d)+(a1+(b-1)*d)) / 2 << endll;
    }

    return 0;
}