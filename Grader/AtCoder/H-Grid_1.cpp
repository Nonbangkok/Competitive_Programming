#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1010, M = 1e9 + 7;
int n,m;
int dp[N][N];
string a[N];

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)cin >> a[i];

    dp[1][1] = 1;
    forr(i,1,n+1)forr(j,1,m+1){
        if(a[i-1][j-1]=='#')continue;
        dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % M;
    }

    cout << dp[n][m];

    return 0;
}