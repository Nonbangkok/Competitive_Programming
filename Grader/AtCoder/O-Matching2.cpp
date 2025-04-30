#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 22, M = 1e9 + 7;
int n;
ll a[N][N],dp[1<<N];

int main(){macos;

    cin >> n;
    forr(i,1,n+1)forr(j,1,n+1)cin >> a[i][j];

    dp[0] = 1LL;
    forr(i,0,1<<n){
        if(!dp[i])continue;
        int j = __builtin_popcount(i) + 1;
        forr(k,1,n+1){
            if(!a[j][k]||i&(1<<(k-1)))continue;
            dp[i|(1<<(k-1))] = (dp[i|(1<<(k-1))] + dp[i]) % M;
        }
    }

    cout << dp[(1<<n)-1];

    return 0;
}