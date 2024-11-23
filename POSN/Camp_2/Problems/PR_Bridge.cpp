#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (short int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=3001;
short int A[N],B[N],dp[N][N],n;
int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> A[i];
    forr(i,1,n+1)cin >> B[i];
    forr(i,1,n+1){
        forr(j,1,n+1){
            if(A[i]==B[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout << dp[n][n];

    return 0;
}