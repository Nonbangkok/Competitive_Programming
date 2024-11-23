#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int dp[101][101];
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n+2)forr(j,0,m+2)dp[i][j]=1e9;
    forr(i,1,n+1)forr(j,1,m+1)cin >> dp[i][j];

    forr(j,2,m+1){
        forr(i,1,n+1){
            dp[i][j]+=min(dp[i-1][j-1],min(dp[i][j-1],dp[i+1][j-1]));
        }
    }

    // forr(i,1,n+1){
    //     forr(j,1,m+1){
    //         cout << setw(2) << dp[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    int mn=1e9;
    forr(i,1,n+1)mn=min(mn,dp[i][m]);
    cout << mn;

    return 0;
}