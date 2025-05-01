#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 510;
int n,m;
ll ans,x;
ll dp[N][N];
pair<ll,ll> a[N];

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1)cin >> a[i].first >> a[i].second;

    forr(i,1,n+1)forr(j,0,n)dp[i][j] = 1e18;
    dp[1][0] = 0LL;
    forr(food,1,n)forr(i,1,n+1)forr(j,1,n+1)
        dp[i][food] = min(dp[i][food],max(dp[j][food-1],abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second)));

    while(m--){
        cin >> x;
        forr(i,1,n)if(dp[n][i]<=x){ans += i;break;}
        // ans += lower_bound(dp[n]+1,dp[n]+n+1,x,greater<ll>()) - dp[n];
    }
    
    cout << ans;

    return 0;
}