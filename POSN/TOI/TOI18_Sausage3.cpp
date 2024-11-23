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
ll n,A[N],dp[N][N],par[N];

int main() {macos;

    cin >> n;
    forr(i,0,n)cin >> A[i];
    forl(l,n-1,-1)forr(r,l,n)dp[l][r]=max(dp[l+1][r]+A[l],dp[l][r-1]+A[r])+abs(A[l]-A[r]);
    forr(l,0,n)forr(r,l,n)par[r]=max(par[r],par[l-1]+dp[l][r]);
    //forr(r,0,n)forr(l,0,r)par[r]=max(par[r],par[l-1]+dp[l][r]);
    cout << par[n-1];

    return 0;
}