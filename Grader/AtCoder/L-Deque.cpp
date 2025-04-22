#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 3010;
int n;
ll a[N],dp[N][N];

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> a[i],dp[i][i] = (n&1?a[i]:-a[i]);

    forr(sz,1,n)forr(l,1,n-sz+1){
        int r = l + sz;
        if((n-sz)&1)dp[l][r] = max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
        else dp[l][r] = min(dp[l+1][r]-a[l],dp[l][r-1]-a[r]);
    }

    cout << dp[1][n];

    return 0;
}