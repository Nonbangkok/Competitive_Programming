#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 410;
int n;
ll a[N],dp[N][N],cost[N][N];

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> a[i],dp[i][i] = a[i];

    forr(sz,1,n)forr(l,1,n-sz+1){
        int r = l + sz;
        dp[l][r] = 1e18;
        forr(k,l,r)if(dp[l][r]>dp[l][k]+dp[k+1][r]){
            dp[l][r] = dp[l][k] + dp[k+1][r];
            cost[l][r] = cost[l][k] + cost[k+1][r] + dp[l][r];
        }else if(dp[l][r]==dp[l][k]+dp[k+1][r])cost[l][r] = min(cost[l][r],cost[l][k] + cost[k+1][r] + dp[l][r]);
    }
    
    cout << cost[1][n];

    return 0;
}