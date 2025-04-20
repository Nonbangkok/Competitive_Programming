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
int n,m,a,b,ans;
int dp[N];
vector<int> adj[N];

int dfs(int u){
    if(dp[u])return dp[u];

    int mx = 0;
    for(int v:adj[u])mx = max(mx,dfs(v));

    return dp[u] = mx + 1;
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    forr(i,1,n+1)ans = max(ans,dfs(i));
    cout << ans - 1;

    return 0;
}