#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e3+10,M=1e9+7;
char A[N][N];
ll dp[N][N];
int main(){macos;

    int n,m;
    cin >> n >> m;
    dp[1][1]=1;
    forr(i,1,n+1)forr(j,1,m+1)cin >> A[i][j];
    forr(i,1,n+1)forr(j,1,m+1)dp[i][j]+=((A[i-1][j]!='#'?dp[i-1][j]:0)+(A[i][j-1]!='#'?dp[i][j-1]:0))%M;
    cout << dp[n][m];

    return 0;
}