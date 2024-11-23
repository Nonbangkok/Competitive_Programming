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

int solve(int i ,int j){
    if(i==-1||j==-1)return 0;
    if(dp[i][j])return dp[i][j];
    if(j<W[i])return dp[i][j]=solve(i-1,j);
    return dp[i][j]=max(solve(i-1,j),V[i]+solve(i-1,j-W[i]));
}

int main() {macos;

    cin >> t;
    while(t--){
        cin >> n >> w;
        forr(i,0,n)cin >> V[i];
        forr(i,0,n)cin >> W[i];
        cout << solve(n-1,w)<< endll;
        memset(dp,0,sizeof(dp));
    }

    return 0;
 }