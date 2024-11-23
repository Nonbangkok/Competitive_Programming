#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e6+10,M = 1e9+7;
ll dp[N];
int main(){macos;

    int n,m;
    cin >> n >> m;

    dp[0] = 1LL;
    forr(i,1,n+1){
        dp[i] += dp[i-1];
        dp[i] %= M;
        if(i-m>=0)dp[i] += dp[i-m];
        dp[i] %= M;
    }
    cout << dp[n];

    return 0;
}