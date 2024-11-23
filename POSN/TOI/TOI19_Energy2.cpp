#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int m=1e9+7;

ll n,k,d,dp[302][302][11],A[302];

int main() {macos;

    cin >> n >> k >> d;
    forr(i,0,n)cin >> A[i];
    forr(i,1,n)A[i]+=A[i-1];
    forr(i,0,n)forr(j,i,n)dp[i][j][1]=1;
    forr(depth,2,k+1)forr(l,0,n)forr(r,l+1,n)forr(j,l,r)
        if(abs(A[r]-(2*A[j])+A[l-1])<=d)dp[l][r][depth]=(dp[l][r][depth]+dp[l][j][depth-1]*dp[j+1][r][depth-1])%m;
    cout << dp[0][n-1][k];

    return 0;
}