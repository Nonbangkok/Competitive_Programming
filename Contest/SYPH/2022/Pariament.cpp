#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int k,n;
    cin >> k >> n;
    int a[n],dp[k+1];
    forr(i,0,n)cin >>a[i];
    memset(dp,0,sizeof(dp));

    dp[0]=1;
    forr(i,0,k+1){
        forr(j,0,n)if(i+a[j]<=k)dp[i+a[j]]+=dp[i];
    }
    cout << dp[k];

    return 0;
}