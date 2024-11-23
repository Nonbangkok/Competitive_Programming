#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=5e6+10,M=1e9+7;
ll dp[N];
int main(){macos;

    ll n,k;
    cin >> n >> k;
    forr(i,1,n+1)cin >> dp[i];
    forr(i,1,n+1)if(i-k-1>0)dp[i]=(max(dp[i-1],(dp[i-k-1]+dp[i])%M));
    else dp[i]=max(dp[i],dp[i-1]);
    //forr(i,1,n+1)cout << dp[i] << sp;
    cout << dp[n];

    return 0;
}