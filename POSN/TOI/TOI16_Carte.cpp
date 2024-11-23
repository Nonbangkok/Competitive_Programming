#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=401;
int dp[N][N],A[N];
int main(){macos;

    int t,k,n,mx=0;
    cin >> t >> k;
    while(t--){
        cin >> n;
        forr(i,0,n)cin >> A[i];
        forr(i,0,n)forr(j,0,n)dp[i][j]=(i==j?1:1e9);
        forr(sz,1,n)forr(l,0,n-sz){
            int r=l+sz;
            forr(m,l,r)dp[l][r]=min(dp[l][r],dp[l][m]+dp[m+1][r]);
            if(A[l]==A[r])dp[l][r]--;
        }
        mx=max(mx,dp[0][n-1]);
    }
    cout << mx;

    return 0;
}