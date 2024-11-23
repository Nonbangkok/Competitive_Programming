#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=202,K=16;
int A[K];
ll dis[N][N],dp[K][1<<K];
int main(){macos;

    int n,m,p,a,b,c;
    ll ans=LLONG_MAX;
    cin >> n >> m >> p;
    forr(i,0,p)cin >> A[i],A[i]--;
    forr(i,0,n)forr(j,0,n)dis[i][j]=(i==j?0:1e9);
    forr(i,0,m){
        cin >> a >> b >> c;a--;b--;
        dis[a][b]=dis[b][a]=c;
    }
    forr(k,0,n)forr(j,0,n)forr(i,0,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    forr(i,0,p)forr(j,0,1<<p)dp[i][j]=1e9;
    forr(i,0,p)dp[i][1<<i]=dis[0][A[i]];
    forr(k,0,1<<p)forr(i,0,p)forr(j,0,p)dp[j][k]=min(dp[j][k],dp[i][k^(1<<j)]+dis[A[i]][A[j]]);
    forr(i,0,p)ans=min(ans,dp[i][(1<<p)-1]+dis[A[i]][n-1]);
    cout << ans;

    return 0;
}