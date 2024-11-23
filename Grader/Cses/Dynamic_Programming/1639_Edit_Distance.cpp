#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 5e3+10;
int dp[N][N];
int main(){macos;

    string a,b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    forr(i,0,n+1)dp[i][0] = i;
    forr(j,0,m+1)dp[0][j] = j;
    forr(i,1,n+1){
        forr(j,1,m+1){
            if(a[i-1]==b[j-1])dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1])) + 1;
        }
    }

    cout << dp[n][m];

    return 0;
}