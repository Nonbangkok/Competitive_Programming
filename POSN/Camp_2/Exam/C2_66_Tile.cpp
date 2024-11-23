#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int A[11],dp[11][10001];

int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n)cin >> A[i];
    forr(i,0,11)forr(j,0,10001)dp[i][j]=1e9;
    
    dp[0][0]=0;
    forr(i,0,n)forr(j,0,m){
        if(dp[i][j]!=1e9)for(int k=1;j+k*k<=m;k++)dp[i+1][j+k*k]=min(dp[i+1][j+k*k],dp[i][j]+(A[i]-k)*(A[i]-k));
    }
    dp[n][m]==1e9?cout << -1:cout << dp[n][m];

    return 0;
}