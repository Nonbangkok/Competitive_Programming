#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 20;
ll n,k,ans=1e18;
ll h[N],dp[N][510];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> h[i];
    forr(i,1,n+1)forr(j,0,k+1)dp[i][j] = 1e18;
    dp[1][k] = 0LL;
    forr(i,2,n+1)forr(j,0,k+1){
        if(j)dp[i][j] = min(dp[i][j],dp[i-1][j-1]+abs(h[i]-h[i-1])); // can used count time
        if(j==k){
            dp[i][j] = min(dp[i][j],dp[i-1][j]+abs(h[i]-h[i-1])); // not used nout count time
            dp[i][0] = min(dp[i][0],dp[i-1][j]); // used reset time
        }
    }
    forr(j,0,k+1)ans = min(ans,dp[n][j]);

    forr(i,1,n+1){
        forr(j,0,k+1){
            if(dp[i][j]==1e18)cout << '-' << sp;
            else cout << dp[i][j] << sp;
        }
        cout << endll;
    }

    cout << ans;

    return 0;
}