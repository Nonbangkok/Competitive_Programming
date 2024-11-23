#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int t,n,w,W[1001],V[1001],dp[1001][1001];
int main() {macos;

    cin >> t;
    while(t--){
        cin >> n >> w;
        forr(i,1,n+1)cin >> V[i];
        forr(i,1,n+1)cin >> W[i];
        forr(i,0,n+1)dp[i][0]=0;
        forr(i,0,w+1)dp[0][i]=0;
        forr(i,1,n)forr(j,1,w)
            if(j<w[i])dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],V[i]+dp[i-1][j-W[i]]);
        cout << dp[n][w] << endll;
    }

    return 0;
 }