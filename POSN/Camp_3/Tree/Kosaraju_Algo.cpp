#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=101;
vector<int> adj[N],rev_adj[N],visited(N),out_node;

void dfs(int u){
    visited[u]=1;
    for(auto v:adj[u])if(!visited[v])dfs(v);
    out_node.push_back(u);
}

void dfs2(int u){
    visited[u]=1;
    for(auto v:rev_adj[u])if(!visited[v])dfs2(v);
}

int main(){macos;

    int V,E,ans=0;
    cin >> V >> E;
    forr(i,0,E){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    forr(i,1,V+1)if(!visited[i])dfs(i);
    forr(i,1,V+1)visited[i]=false;
    reverse(out_node.begin(),out_node.end());
    for(auto u:out_node)if(!visited[u])dfs2(u),ans++;
    cout << ans;

    return 0;
}