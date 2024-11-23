#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const ll N=1e7+10,M=1e18+7;
ll dp[N][2][2];
int main(){macos;

    ll n;
    cin >> n;
    dp[1][0][0]=dp[1][0][1]=1;
    forr(i,2,n+1){
        dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][0][1])%M;
        dp[i][0][1]=dp[i-1][0][0];
        dp[i][1][0]=(dp[i-1][1][0]+dp[i-1][1][1])%M;
        dp[i][1][1]=(dp[i-1][1][0]+(dp[i-1][1][1]+dp[i-1][0][1])%M)%M;
    }
    cout<< (dp[n][1][0]+dp[n][1][1])%M;

    return 0;
}