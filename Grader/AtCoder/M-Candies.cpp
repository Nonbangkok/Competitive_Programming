#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10, M = 1e9 + 7;
int n,k;
ll a[110],qs[N],dp[110][N];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> a[i];

    dp[0][0] = 1LL;
    forr(i,1,n+1){
        qs[0] = dp[i-1][0];
        forr(j,1,k+1)qs[j] = (qs[j-1] + dp[i-1][j]) % M;
        forr(j,0,k+1){
            if(j-a[i]-1>=0)dp[i][j] = (dp[i][j] + (qs[j] - qs[j-a[i]-1] + M) % M) % M;
            else dp[i][j] = (dp[i][j] + qs[j]) % M;
        }
    }

    // forr(i,0,n+1)dp[i][0] = 1LL;
    // forr(i,1,n+1)forr(j,1,k+1)forr(l,0,a[i]+1)
    //     if(j-l>=0)dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % M; 

    cout << dp[n][k];

    return 0;
}