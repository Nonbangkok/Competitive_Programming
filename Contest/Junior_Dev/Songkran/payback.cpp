#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5e3 + 10;
int n;
bool chk = true;
int dis[N][N];
int ans[N];
vector<int> adj[N];

void dfs(int i, int u, int p, int d){
    dis[i][u] = d;
    for(int v:adj[u])if(v!=p)dfs(i,v,u,d+1);
}

int main(){macos;

    cin >> n;

    forr(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(adj[u].size()>2||adj[v].size()>2)chk = false;
    }

    if(chk){
        forl(i,n,0)cout << i << sp;
        return 0;
    }

    forr(i,1,n+1)dfs(i,i,i,0);

    forr(i,1,n+1)forr(j,1,i+1)ans[dis[i][j]]++;
    forr(i,0,n)cout << ans[i] << sp;
    
    return 0;
}