#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<int> adj[101];
int in_time[101],out_time[101];
int up[101][21]; //Vertex,Depth
int timestep=0;

void precompute(int u,int p){
    in_time[u]=timestep++;

    up[u][0]=p;
    forr(i,1,21)up[u][i]=up[up[u][i-1]][i-1];

    for(auto v:adj[u]){
        if(v==p)continue;
        precompute(v,u);
    }

    out_time[u]=timestep++;
}

bool is_ancestor(int u,int v){
    return in_time[u] <= in_time[v] && out_time[u] >= out_time[v];
}

int lca(int u,int v){ 
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    forl(i,20,-1)if(up[u][i]&&!is_ancestor(up[u][i],v))u=up[u][i];
    return up[u][0];
}

int main(){macos;

    int V,q;
    cin >> V >> q;

    forr(i,0,V-1){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    precompute(1,0);

    // forr(i,1,V+1){
    //     forr(j,0,21){
    //         cout << up[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    while(q--){
        int a,b;
        cin >> a >> b;
        cout << lca(a, b) << endll;
    }

    return 0;
}
/*
15 10
1 2
1 3
2 4 
2 5
3 6
3 7
4 8 
4 9 
5 10
5 11
6 12
6 13
7 14
7 15
Query (?)
*/