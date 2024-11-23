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
ll dp[N][N];
int main(){macos;

    int a,b;
    cin >> a >> b;

    forr(i,1,min(a,b)+1)dp[i][i] = 0;
    forr(i,1,a+1){
        forr(j,1,b+1){ 
            if(i==j)continue;
            dp[i][j] = INT_MAX;
            forr(k,1,i)dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            forr(k,1,j)dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
    }

    cout << dp[a][b];

    return 0;
}