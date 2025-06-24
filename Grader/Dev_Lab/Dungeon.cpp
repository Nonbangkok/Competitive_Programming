#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int main(){macos;

    int n,x;
    cin >> n;
    int dp[n];
    dp[0] = 0;
    forr(i,1,n)dp[i] = 1e9;
    forr(i,0,n-1){
        cin >> x;
        x--;
        if(x)dp[x] = min(dp[x],dp[i]+1);
        dp[i+1] = min(dp[i+1],dp[i]+1);
    }
    
    cout << dp[n-1];

    return 0;
}