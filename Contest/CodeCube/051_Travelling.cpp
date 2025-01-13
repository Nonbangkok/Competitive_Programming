#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 210 , K = 17;
int dis[N][N],dp[K][1<<K],flag[K];
int n,m,k,a,b,c,ans=1e9;

int main(){macos;

    cin >> n >> m >> k;
    forr(i,0,k)cin >> flag[i],flag[i]-=1;
    forr(i,0,n)forr(j,0,n)dis[i][j] = (i==j?0:1e9);
    forr(i,0,m)cin >> a >> b >> c,a-=1,b-=1,dis[a][b] = dis[b][a] = min(dis[a][b],c);
    forr(l,0,n)forr(j,0,n)forr(i,0,n)dis[i][j] = min(dis[i][j],dis[i][l]+dis[l][j]);
    forr(i,0,k)forr(j,0,1<<k)dp[i][j] = 1e9;
    forr(i,0,k)dp[i][1<<i] = dis[0][flag[i]];   
    forr(l,0,1<<k)forr(i,0,k)forr(j,0,k)dp[i][l] = min(dp[i][l],dp[j][l^(1<<i)]+dis[flag[j]][flag[i]]);
    forr(i,0,k)ans = min(ans,dp[i][(1<<k)-1]+dis[flag[i]][n-1]);    
    cout << ans;

    return 0;
}