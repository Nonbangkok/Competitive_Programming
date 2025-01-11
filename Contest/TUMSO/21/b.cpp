#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

void solve(){
    ll n,m;
    cin >> n >> m;
    ll a[n],b[m];
    forr(i,0,n)cin >> a[i];
    forr(i,0,m)cin >> b[i];
    sort(a,a+n);
    sort(b,b+m,greater<ll>());
    ll ans = 0;
    forr(i,0,min(n,m))ans += max(0LL,b[i]-a[i]);
    cout << ans << endll;
}

int main(){macos;

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}