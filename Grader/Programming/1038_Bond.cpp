#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 21;
double a[N][N],dp[1<<N];
int n;

int main(){macos;

    cin >> n;
    forr(i,0,n)forr(j,0,n)cin >> a[i][j],a[i][j] /= 100.0;

    dp[0] = 1.0;
    forr(i,0,1<<n){
        int j = __builtin_popcount(i);
        forr(k,0,n)dp[i|(1<<k)] = max(dp[i|(1<<k)],dp[i]*a[j][k]);
    }

    coutf(12,dp[(1<<n)-1]*100.0);

    return 0;
}