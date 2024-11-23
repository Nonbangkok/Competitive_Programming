#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1001,MOD=1e9+7;
char A[N][N];
int dp[N][N][3];
int main(){macos;

    int t,n,m;
    cin >> t;

    while(t--){
        cin >> n >> m;
        forr(i,1,n+1)forr(j,1,m+1)cin >> A[i][j];
        dp[1][1][1]=dp[1][1][2]=1;
        forr(i,1,n+1)forr(j,1,m+1){
            if(A[i][j]=='*')continue;
            dp[i][j][0]+=dp[i-1][j][0]+dp[i][j-1][0]+dp[i-1][j][1]+dp[i][j-1][2];
            dp[i][j][1]+=dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][2]+=dp[i][j-1][0]+dp[i][j-1][2];
            dp[i][j][0]%=MOD;
            dp[i][j][1]%=MOD;
            dp[i][j][2]%=MOD;

        }

        // forr(i,1,n+1){
        //     forr(j,1,m+1){
        //         cout << dp[i][j][0] << sp;
        //     }
        //     cout << endll;
        // }
        cout << dp[n][m][0] << endll;
    }

    return 0;
}