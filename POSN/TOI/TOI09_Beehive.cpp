#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1010;
int dp[N][N],cnt[N][N];
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,1,n+1)forr(j,1,m+1)cin >> dp[i][j];
    forr(i,1,m+1)cnt[1][i]=1;
    forr(i,2,n+1)forr(j,1,m+1){
        if(i&1){
            dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
            cnt[i][j]=(dp[i-1][j]>=dp[i-1][j-1]?cnt[i-1][j]:0)+(dp[i-1][j]<=dp[i-1][j-1]?cnt[i-1][j-1]:0);
        }else{
            dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1]);
            cnt[i][j]=(dp[i-1][j]>=dp[i-1][j+1]?cnt[i-1][j]:0)+(dp[i-1][j]<=dp[i-1][j+1]?cnt[i-1][j+1]:0);
        }   
    }

    int ans=0,co=0;
    forr(i,1,m+1){
        if(ans<dp[n][i])ans=dp[n][i],co=cnt[n][i];
        else if(ans==dp[n][i])co+=cnt[n][i];
    }
    cout << ans << sp << co;

    return 0;
}