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

    int n;
    cin >> n;
    forr(i,0,n)cin >> dp[i][i];

    forr(sz,1,n){
        forr(i,0,n-sz){
            int j = i+sz;
            dp[i][j] = max(dp[i][i]-dp[i+1][j],dp[j][j]-dp[i][j-1]);
        }
    }

    forr(i,0,n){
        forr(j,0,n)cout << dp[i][j] << sp;
        cout << endll;
    }

    cout << dp[0][n-1];
    //not finish

    return 0;
}