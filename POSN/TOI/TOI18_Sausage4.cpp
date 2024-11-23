#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=5000+10;
ll n,A[N],dp[N][N];

int main() {macos;

    cin >> n;
    forr(i,0,n)cin >> A[i];
    forl(l,n-1,-1)forr(r,l,n)dp[l][r]=max(dp[l+1][r]+A[l],dp[l][r-1]+A[r])+abs(A[l]-A[r]);
    forr(r,0,n)forr(k,0,r)dp[0][r]=max(dp[0][r],dp[0][k]+dp[k+1][r]);
    //forr(l,0,n)forr(r,l+1,n)forr(k,l,r)dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
    //forr(l,0,n)forr(k,l,n)dp[l][n-1]=max(dp[l][n-1],dp[l][k]+dp[k+1][n-1]);

    cout << dp[0][n-1];

    return 0;
}