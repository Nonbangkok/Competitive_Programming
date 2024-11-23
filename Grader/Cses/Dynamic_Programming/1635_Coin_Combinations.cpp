#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=101,M=1e6+10,MOD=1e9+7;
int A[N],dp[M];
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n)cin >> A[i];
    
    dp[0]=1;
    forr(i,0,m+1)forr(j,0,n)
        if(i-A[j]>=0)dp[i]=(dp[i]+dp[i-A[j]])%MOD;
    cout << dp[m];

    return 0;
}