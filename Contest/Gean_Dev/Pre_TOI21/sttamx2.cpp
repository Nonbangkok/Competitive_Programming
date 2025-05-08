#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int pre,now = 1;
ll n,k,ans=1e18;
ll h[N],dp[2][510];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> h[i];
    forr(j,0,k+1)dp[0][j] = dp[1][j] = 1e18;
    dp[pre][k] = 0LL;
    forr(i,2,n+1){
        forr(j,0,k+1)dp[now][j] = 1e18;
        forr(j,0,k+1){
            if(j)dp[now][j] = min(dp[now][j],dp[pre][j-1]+abs(h[i]-h[max(1,i-j)])); // can used count time
            if(j==k){
                dp[now][j] = min(dp[now][j],dp[pre][j]+abs(h[i]-h[max(1,i-j)])); // not used nout count time
                dp[now][0] = min(dp[now][0],dp[pre][j]); // used reset time
            }

            if(i==n)ans = min(ans,dp[now][j]);
        }
        swap(pre,now);
    }

    forr(i,1,4){
        forr(j,0,k+1){
            if(dp[i][j]==1e18)cout << '-' << sp;
            else cout << dp[i][j] << sp;
        }
        cout << endll;
    }

    cout << ans;

    return 0;
}