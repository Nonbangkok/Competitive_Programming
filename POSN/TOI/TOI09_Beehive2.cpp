#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1010;
int A[N][N],dp[N][N],cnt[N][N];
int n,m,ans,co;

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1)forr(j,1,m+1)cin >> A[i][j];
    forr(j,1,m+1)dp[1][j] = A[1][j],cnt[1][j] = 1;
    forr(i,2,n+1)forr(j,1,m+1)forr(k,-1+!(i&1),1+!(i&1)){
        if(dp[i][j] < dp[i-1][j+k]+A[i][j]){
            dp[i][j] = dp[i-1][j+k]+A[i][j];
            cnt[i][j] = cnt[i-1][j+k];
        }else if(dp[i][j] == dp[i-1][j+k]+A[i][j])cnt[i][j] += cnt[i-1][j+k];
    }

    forr(j,1,m+1){
        if(ans < dp[n][j])ans=dp[n][j],co=cnt[n][j];
        else if(ans == dp[n][j])co+=cnt[n][j];
    }

    cout << ans << sp << co;

    return 0;
}