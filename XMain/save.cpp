#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e3+10;
int dp[N][N];
int n,m;

int main(){macos;

    cin >> n >> m;
    // dp[0][0] = 1;
    forr(i,0,n+1) dp[i][0] = dp[0][i] = 1;
    forr(i,1,n+1){
        forr(j,1,m+1){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(i-3>=0)dp[i][j] += dp[i-3][j];
            if(j-3>=0)dp[i][j] += dp[i][j-3];
        }
    }

    cout << dp[n][m]+1;

    return 0;
}