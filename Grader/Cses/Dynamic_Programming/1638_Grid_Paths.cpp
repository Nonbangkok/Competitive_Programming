#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1001,M=1e9+7;
char A[N][N];
int dp[N][N];
int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n+1)forr(j,1,n+1)cin >> A[i][j];

    if(A[1][1]!='*')dp[1][1]=1;
    forr(i,1,n+1)forr(j,1,n+1){
        if(A[i][j]=='*')continue;
        dp[i][j]+=dp[i][j-1];
        dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
    }
    cout << dp[n][n];

    return 0;
}