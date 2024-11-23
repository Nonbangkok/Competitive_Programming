#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (long long i = a; i < n; i++)
#define forl(i, a, n) for (long long i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
ll dp[501][501];
vector<pair<ll,ll>> A;
int main(){macos;

    ll n,m,k,a,b;
    cin >> n >> m;

    forr(i,0,n){cin >> a >> b;A.push_back({a,b});}

    forr(i,0,n)forr(j,0,n)dp[i][j]=LLONG_MAX;
    dp[0][0]=0LL;
    forr(food,1,n)forr(node,1,n)forr(prev_node,0,n)
        dp[node][food]=min(dp[node][food],max(dp[prev_node][food-1],abs(A[node].first-A[prev_node].first)+abs(A[node].second-A[prev_node].second)));

    ll cnt=0;
    forr(i,0,m){
        cin >> k;
        forr(j,1,n)if(dp[n-1][j]<=k){cnt+=j;break;}
        // cnt += (lower_bound(dp[n-1]+1,dp[n-1]+n+1,k,greater<ll>())-dp[n-1]);
    }
    cout << cnt;

    return 0;
}