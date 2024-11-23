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

    int n,m;
    cin >> n >> m;
    int A[n][m],dp[n][m];
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];

    forr(i,0,n){
        forr(j,0,m){
            if(!(i+j))dp[i][j]=A[i][j];
            else if(!i)dp[i][j]=dp[i][j-1]+A[i][j];
            else if(!j)dp[i][j]=dp[i-1][j]+A[i][j];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1])+A[i][j];
        }
    }
    cout << dp[n-1][m-1];

    return 0;
}