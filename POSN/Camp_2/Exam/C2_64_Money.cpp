#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=1005;
ll dp[N][N];

int main() {macos;

    ll k,n,t,ans,idx;
    cin >> k;
    while(k--){
        ans=-1;
        cin >> n >> t;
        forr(i,1,t+1)forr(j,1,n+1)cin >> dp[i][j];
        //forr(i,1,t+1)forr(j,1,n+1)dp[i][j]+=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
        //forr(i,1,n+1){if(dp[t][i]>ans){ans=dp[t][i];idx=i;}}
        forl(i,t,0)forr(j,1,n+1)dp[i][j]+=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));
        forr(i,1,n+1){if(dp[1][i]>ans){ans=dp[1][i];idx=i;}}

        // cout << endll;
        // forr(i,1,t+1){
        //     forr(j,1,n+1){
        //         cout << dp[i][j] << sp;
        //     }
        //     cout << endll;
        // }
        // cout << endll;

        forr(i,1,t+1)forr(j,1,n+1)dp[i][j]=0;
        cout << idx << sp << ans << endll;
    }

    return 0;
}