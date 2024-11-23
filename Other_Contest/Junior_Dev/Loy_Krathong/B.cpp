#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 510, M = 1e9+7;
int dp[2][N][N], ans;

int main(){macos;

    int n, m, K, now = 1, prev = 0;
    cin >> n >> m >> K;

    dp[prev][0][0] = 1;
    forr(i,1,n+1){
        memset(dp[now],0,sizeof(dp[now]));
        forr(j,0,m+1){
            forr(k,0,K+1){
                if(!dp[prev][j][k])continue;
                dp[now][j+1][k+1] = (dp[now][j+1][k+1]+dp[prev][j][k])%M;
                dp[now][j][0] = (dp[now][j][0]+dp[prev][j][k])%M;
            }
        }
        swap(prev,now);
    }

    ll ans = 0;
    forr(i,0,K+1)ans = (ans+dp[prev][m][i])%M;
    cout << ans;

    return 0;
}