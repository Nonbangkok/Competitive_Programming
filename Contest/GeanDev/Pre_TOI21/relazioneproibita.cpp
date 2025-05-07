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
int n,a,b;
ll p[4],t[N],dp[N][2];
vector<int> adj[N];

void dfs(int u, int pa){
    if(u!=1)dp[u][1] = p[t[u]];
    for(int v:adj[u]){
        if(v==pa)continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        if(!t[u])continue;
        if(t[u]==1&&t[v]==3)dp[u][1] += max(dp[v][0],dp[v][1]);
        else dp[u][1] += dp[v][0];
    }
}

int main(){macos;

    cin >> n;
    forr(i,1,4)cin >> p[i];
    forr(i,1,n+1)cin >> t[i];t[1] = -1;
    forr(i,1,n){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    cout << dp[1][0];

    return 0;
}