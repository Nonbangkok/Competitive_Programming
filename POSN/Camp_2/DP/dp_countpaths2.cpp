#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int M=1e9+7;
int dp[101][101];
int main(){macos;

    int t,n,m;
    cin >> t;

    while(t--){
        cin >> n >> m;
        forr(i,1,n+1){
            forr(j,1,m+1){
                if(i==1&&j==1)dp[i][j]=1;
                else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
            }
        }
        cout << dp[n][m] << endll;
        memset(dp,0,sizeof(dp));
    }

    return 0;
}