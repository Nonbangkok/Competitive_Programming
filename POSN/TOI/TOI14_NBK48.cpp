#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5+10;
int n,q,m,dp[N];

int main(){macos;

    cin >> n >> q;
    forr(i,1,n+1)cin >> dp[i],dp[i] += dp[i-1];
    forl(i,n-1,0)dp[i] = min(dp[i],dp[i+1]);

    while(q--){
        cin >> m;
        cout << upper_bound(dp+1,dp+n+1,m)-dp-1 << endll;
    }

    return 0;
}