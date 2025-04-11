#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 16;
ll dp[1<<N];
ll n,m,a,bit,w;

int main(){macos;

    cin >> n >> m;
    forr(i,1,1<<m)dp[i] = 1e18;
    forr(i,0,n){
        cin >> w;
        bit = 0;
        forr(j,0,m)cin >> a,bit  |= (a<<j);
        if(w>dp[bit])continue;
        // forr(j,0,1<<m)dp[j|bit] = min(dp[j|bit],dp[j]+w);
        forr(j,0,1<<m)if(dp[j|bit]>dp[j]+w)dp[j|bit] = dp[j]+w;
    }

    cout << dp[(1<<m)-1];

    return 0;
}