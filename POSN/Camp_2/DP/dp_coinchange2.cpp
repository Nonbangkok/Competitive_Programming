#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n;
    cin >> n;
    int dp[n];
    dp[0]=0;
    forr(i,1,n+1){
        dp[i]=1e9;
        if(i>=1)dp[i]=min(dp[i],1+dp[i-1]);
        if(i>=3)dp[i]=min(dp[i],1+dp[i-3]);
        if(i>=4)dp[i]=min(dp[i],1+dp[i-4]);
    }
    cout << dp[n];

    return 0;
 }