#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N][4],dp[N][4];

int main(){macos;

    cin >> n;
    forr(i,1,n+1)forr(j,1,4)cin >> a[i][j];

    forr(i,1,n+1)forr(j,1,4)forr(k,1,4){
        if(j==k)continue;
        dp[i][j] = max(dp[i][j],dp[i-1][k]+a[i][j]);
    }

    cout << max({dp[n][1],dp[n][2],dp[n][3]});

    return 0;
}