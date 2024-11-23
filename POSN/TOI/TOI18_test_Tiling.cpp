#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int M=1e9+7;
int main() {macos;

    int n;
    cin >> n;
    int dp[n];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    forr(i,3,n+1)dp[i]=(((2*dp[i-1])%M)+dp[i-3])%M;
    cout << dp[n];

    return 0;
}