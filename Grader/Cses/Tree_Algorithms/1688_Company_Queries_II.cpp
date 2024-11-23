#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

// LCA
const int N = 2e5+10, LOG = 20;
int up[N][LOG],in[N],out[N];
int n,q,a,b,timer;
vector<int> adj[N];

void precompute(int u, int p){
    in[u] = timer++;

    up[u][0] = p;
    forr(i,1,LOG)up[u][i] = up[up[u][i-1]][i-1];

    for(int v:adj[u]){
        if(v==p)continue;
        precompute(v,u);
    }

    out[u] = timer++;
}

bool is_ancestor(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v){
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    forl(i,LOG-1,-1)if(!is_ancestor(up[u][i],v))u = up[u][i];
    return up[u][0];
}

int main(){macos;

    cin >> n >> q;
    forr(i,2,n+1){
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    precompute(1,1);

    while(q--){
        cin >> a >> b;
        cout << lca(a,b) << endll;
    }


    return 0;
}