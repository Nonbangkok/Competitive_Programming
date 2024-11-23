#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
ll mp[100000];
int main(){macos;

    ll n, mx = 0,idx;
    cin >> n;

    forr(i,0,n){
        ll a,b;
        cin >> a >> b;
        ll k = (abs(a)+abs(b))<<1;
        mp[k]++;
        if(mx<mp[k]){
            mx = mp[k];
            idx = k;
        }
        if(mx==mp[k] && idx>k){
            idx = k;
        }
    }

    cout << idx << sp << mx;

    return 0;
}