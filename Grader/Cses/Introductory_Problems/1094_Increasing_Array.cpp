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

    ll n,mx,x,sum=0;
    cin >> n >> mx;
    forr(i,1,n){
        cin >> x;
        mx=max(mx,x);
        sum+=(mx-x);
    }
    cout << sum;

    return 0;
}