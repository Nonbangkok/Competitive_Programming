#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
ll dp[60];
int main(){macos;

    ll n;
    cin >> n;
    dp[1]=dp[3]=dp[4]=1;
    forr(i,0,n+1){
        if(i-1>=0)dp[i]+=dp[i-1];
        if(i-3>=0)dp[i]+=dp[i-3];
        if(i-4>=0)dp[i]+=dp[i-4];
    }
    cout << dp[n];

    return 0;
}