#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int m,n;
    cin >> m >> n;
    int A[m+2][n+2],dp[m+2][n+2];
    memset(dp,0,sizeof(dp));

    forr(i,1,m+1){
        forr(j,1,n+1){
            cin >> A[i][j];
        }
    }

    int mx=0;
    forr(i,1,m+1){
        forr(j,1,n+1){
            dp[i][j] = A[i][j]+max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
            if(i==m){
                mx=max(mx,dp[i][j]);
            }
        }
    }
    cout << mx;

    return 0;
 }