#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e3+10;
int n,m,a,b,mx = 0;
set<pair<int,int>> ans;
vector<int> adj[N];
int visited[N];

void dfs(int u,int d,int p){
    visited[u] = d;
    if(d>mx)mx = d,ans.clear();
    if(d==mx) ans.insert({min(u,p),max(u,p)});

    for(int v:adj[u]){
        if(visited[v]>d+1)continue;
        dfs(v,d+1,p);
    }
}

int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[min(a,b)].push_back(max(a,b));
    }

    forr(i,1,n+1){
        forr(j,1,n+1)visited[j] = false;
        dfs(i,0,i);
    }

    cout << mx << endll;
    for(auto [u,v]:ans)cout << '(' << u << ',' << v << ')' << sp;

    return 0;
}