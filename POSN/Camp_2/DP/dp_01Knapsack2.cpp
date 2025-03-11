#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1001;
int v[N],w[N],dp[N][N];
int n,m;

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1)cin >> v[i] >> w[i];

    forr(i,1,n+1)forr(j,0,m+1){
        if(j-w[i]>=0)dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        else dp[i][j] = dp[i-1][j];
    }
    cout << dp[n][m];

    return 0;
}