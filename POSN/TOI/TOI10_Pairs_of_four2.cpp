#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

char ch[1001];
int dp[1001][1001];

int main() {macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> ch[i];

    forl(l,n-1,-1)forr(r,l+1,n)
    if(ch[l]==ch[r])dp[l][r]=dp[l+1][r-1]+1;
    else forr(k,l,r)dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);

    // forr(sz,1,n)forr(l,0,n-sz){
    //     int r=l+sz;
    //     if(ch[l]==ch[r])dp[l][r]=dp[l+1][r-1]+1;
    //     else forr(k,l,r)dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
    // }
    cout << dp[0][n-1];
    
    return 0;
}