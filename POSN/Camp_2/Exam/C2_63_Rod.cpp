#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1002;
int dp[N][N];
int main() {macos;

    int n,m,k,mx=-1,big,small;
    cin >> n >> m >> k;
    forr(i,1,n+1)forr(j,1,m+1)cin >> dp[i][j];
    forr(i,1,n+1)forr(j,1,m+1)dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    forr(i,1,n-k+2){
        forr(j,1,m-k+2){
            big=dp[i+k-1][j+k-1]-dp[i+k-1][j-1]-dp[i-1][j+k-1]+dp[i-1][j-1];
            small=dp[i+k-2][j+k-2]-dp[i+k-2][j]-dp[i][j+k-2]+dp[i][j];
            mx=max(mx,big-small);
        }
    }
    cout << mx;

    return 0;
}