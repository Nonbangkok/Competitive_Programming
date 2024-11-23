#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2e6+10, M = 1e9+7;
ll dp[N][2];
int main(){macos;

    dp[1][0] = dp[1][1] = 1;
    forr(i,2,N){
        dp[i][0] = (dp[i-1][0]*4 + dp[i-1][1]) %M;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2) %M;
    }

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) %M << endll;
    }

    return 0;
}