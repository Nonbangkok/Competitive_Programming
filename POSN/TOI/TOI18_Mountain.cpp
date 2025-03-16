#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 510;
ll n,m,ans,x;
ll dp[N][N];
pair<ll,ll> coor[N];

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)cin >> coor[i].first >> coor[i].second;

    forr(i,0,n)forr(j,0,n)dp[i][j] = LLONG_MAX;
    dp[0][0] = 0LL;
    forr(j,1,n)forr(i,1,n)forr(k,0,n)
        dp[i][j] = min(dp[i][j],max(dp[k][j-1],abs(coor[i].first-coor[k].first)+abs(coor[i].second-coor[k].second)));

    while(m--){
        cin >> x;
        forr(i,1,n)if(dp[n-1][i]<=x){ans+=i;break;}
        // ans += lower_bound(dp[n-1],dp[n-1]+n,x,greater<ll>()) - dp[n-1];
    }

    cout << ans;

    return 0;
}