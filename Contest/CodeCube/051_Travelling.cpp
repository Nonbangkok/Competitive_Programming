#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 210, K = 15;
int n,m,p,a,b,c,ans = 1e9;
int flag[N];
int dis[N][N],dp[K][1<<K];

int main(){macos;

    cin >> n >> m >> p;
    forr(i,0,p)cin >> flag[i];
    forr(i,1,n+1)forr(j,1,n+1)dis[i][j] = (i!=j?1e9:0);
    forr(i,0,m)cin >> a >> b >> c,dis[a][b] = dis[b][a] = c;
    forr(k,1,n+1)forr(j,1,n+1)forr(i,1,n+1)dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    forr(i,0,1<<p)forr(j,0,p)dp[j][i] = 1e9;
    forr(i,0,p)dp[i][1<<i] = dis[1][flag[i]];
    forr(i,0,1<<p)forr(j,0,p)forr(k,0,p)dp[j][i] = min(dp[j][i],dp[k][i^(1<<j)]+dis[flag[k]][flag[j]]);
    forr(i,0,p)ans = min(ans,dp[i][(1<<p)-1]+dis[flag[i]][n]);
    cout << ans;

    return 0;
}