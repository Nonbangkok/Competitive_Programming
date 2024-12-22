#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
#define int long long
using namespace std;

const int M = (1<<16);
int n,m,a,cost,prop,dp[M];

int32_t main(){macos;

    cin >> n >> m;
    forr(i,1,1<<m)dp[i] = 1e18;
    forr(i,0,n){
        cin >> cost;
        prop = 0;
        forr(j,0,m)cin >> a,prop |= (a<<j);
        if(cost >= dp[prop])continue;
        // forr(j,0,1<<m)dp[j|prop] = min(dp[j|prop],dp[j]+cost);
        forr(j,0,1<<m)if(dp[j|prop]>dp[j]+cost)dp[j|prop]=dp[j]+cost;
    }

    cout << dp[(1<<m)-1];

    return 0;
}