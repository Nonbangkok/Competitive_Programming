#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int dp[2][20001],qs[1001];
int main(){macos;

    int n,m,s,ans=0;
    cin >> n >> s;

    forr(i,1,n+1){
        cin >> m;
        forr(j,1,m+1)cin >> qs[j],qs[j]+=qs[j-1];
        memset(dp[i&1],0,sizeof(dp[i&1]));
        forr(j,1,s+2){
            forr(k,0,min(m,j-i)+1)dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j-k-1]+qs[k]);
            ans=max(ans,dp[i&1][j]);
        }
    }
    cout << ans;

    return 0;
}