#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,a,b;
int d1,d2,mx;
int dis1[N],dis2[N];
vector<int> adj[N];

void dfs1(int u, int p ,int d){
    if(mx<d)mx = d, d1 = u;

    for(int v:adj[u]){
        if(v==p)continue;
        dfs1(v,u,d+1);
    }
}

void dfs2(int u, int p ,int d){
    if(mx<d)mx = d, d2 = u;

    for(int v:adj[u]){
        if(v==p)continue;
        dfs2(v,u,d+1);
    }

    dis1[u] = d;
}

void dfs3(int u, int p ,int d){

    for(int v:adj[u]){
        if(v==p)continue;
        dfs3(v,u,d+1);
    }

    dis2[u] = d;
}


int main(){macos;

    cin >> n;
    forr(i,0,n-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1,-1,0);

    mx = 0;
    dfs2(d1,-1,0);
    dfs3(d2,-1,0);

    forr(i,1,n+1)cout << max(dis1[i],dis2[i]) << sp;

    return 0;
}