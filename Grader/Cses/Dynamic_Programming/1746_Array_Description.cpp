#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10,M=1e9+7;
ll dp[N][101],A[N];
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n)cin >> A[i];

    forr(i,0,n){
        if(i==0){
            if(!A[i])forr(j,1,m+1)dp[i][j]=1;
            else dp[i][A[i]]=1;
        }else{
            if(!A[i])forr(j,1,m+1)dp[i][j]=(dp[i][j]+dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%M;
            else dp[i][A[i]]=(dp[i][A[i]]+dp[i-1][A[i]-1]+dp[i-1][A[i]]+dp[i-1][A[i]+1])%M;
        }
    }
    ll ans=0;
    forr(i,1,m+1)ans=(ans+dp[n-1][i])%M;
    cout << ans;

    return 0;
}