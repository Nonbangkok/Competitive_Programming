#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 50;
ll dp[N][N];
int main() {macos;

    int n,m;
    cin >> n >> m;

    forr(i,0,n){
        forr(j,0,m){
            if((i==1&&j==2)||(i==2&&j==1))dp[i][j]=1;
            if(i>=1&&j>=2)dp[i][j]+=dp[i-1][j-2];
            if(i>=2&&j>=1)dp[i][j]+=dp[i-2][j-1];
        }
    }
    cout << dp[n-1][m-1];

    return 0;
}