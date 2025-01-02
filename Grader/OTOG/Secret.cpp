#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 205 , R = 1505 , M = 1e7+9;
int n,m,r;
char A[N][N];
int dp[N][N][R];

int main(){macos;


    cin >> n >> m >> r;
    forr(i,1,n+1)forr(j,1,m+1)cin >> A[i][j];

    dp[1][1][0] = 1;

    forr(k,0,r+1){
        forr(i,1,n+1){
            forr(j,1,m+1){
                if(A[i][j]=='#'||(i==1&&j==1))continue;
                dp[i][j][k] = (dp[i-1][j][k-(A[i][j]=='X')]+dp[i][j-1][k-(A[i][j]=='X')])%M;
            }
        }
    }

    ll ans = 0;
    forr(i,0,r+1)ans = (ans+dp[n][m][i])%M;
    cout << ans;

    return 0;
}