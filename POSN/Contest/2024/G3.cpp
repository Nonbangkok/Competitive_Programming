#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

bool mark[(int)2e5+1];
vector<int> adj[(int)2e5+1];

void dfs(int u,int p){
    for(auto v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        if(mark[v])mark[u]=true;
    }
}

int main(){macos;

    int n,k,u,v,cnt=0,x;
    cin >> n >> k;
    forr(i,0,n-1){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    forr(i,0,k){
        cin >> x;
        mark[x]=true;
    }
    dfs(x,0);
    forr(i,1,n+1)if(mark[i])cnt++;
    cout << cnt;

    return 0;
}