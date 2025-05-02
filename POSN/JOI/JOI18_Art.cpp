#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5e5 + 10;
ll n,ans;
ll dp[N];
pair<ll,ll> a[N];

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> a[i].first >> a[i].second;
    sort(a,a+n);

    forr(i,0,n){
        dp[i] = max(dp[i-1] + a[i-1].first - a[i].first + a[i].second,a[i].second);
        ans = max(ans,dp[i]);
    }

    cout << ans;
    
    return 0;
}