#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10, M = 1e9 + 7;
int n,m,a,b;
int vis[N];
ll dis[N];
vector<int> adj[N],node;

void dfs(int u){
    if(vis[u])return;
    vis[u] = true;
    for(int v:adj[u])dfs(v);
    node.push_back(u);
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);
    reverse(node.begin(),node.end());

    dis[1] = 1;
    for(int u:node)for(int v:adj[u])dis[v] = (dis[v] + dis[u]) % M;

    cout << dis[n];

    return 0;
}