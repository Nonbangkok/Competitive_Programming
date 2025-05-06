#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6 + 10;
int n,k;
int a[N],dp[2][N];
vector<int> adj[N];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1){
        cin >> a[i];
        adj[a[i]].push_back(i);
    }

    forr(i,1,n+1){
        vector<int> &v = adj[a[i]];
        int sz = v.size();
        if(i==v.back()){
            dp[0][i] = dp[0][v.front()-1] + sz;
            dp[1][i] = dp[1][v.front()-1] + sz;
            if(sz>1)dp[1][i] = max(dp[1][i],dp[0][v[1]-1]+sz-1);
        }else if(sz>1&&i==v[sz-2])dp[1][i] = dp[0][v.front()-1] + sz - 1;
        dp[0][i] = max(dp[0][i],dp[0][i-1]);
        dp[1][i] = max(dp[1][i],dp[1][i-1]);
    }

    if(k)cout << n - max(dp[0][n],dp[1][n]);
    else cout << n - dp[0][n];

    return 0;
}