#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=5e5+10;
vector<int> adj[N];
vector<bool> visited(N);
int n,st,a,b,node=N,mx=0;

int dfs(int u,int p){
    visited[u]=1;
    int cnt=0;
    bool cycle=false;
    for(auto v:adj[u]){
        if(v==p)continue;
        if(v==st)cycle=true;
        if(visited[v])continue;
        int tmp=dfs(v,u);
        if(!tmp)cycle=true;
        cnt+=tmp;
    }
    if(u==st)return 0;
    if(cnt>mx)mx=cnt,node=u;
    else if(cnt==mx)node=min(node,u);
    if(cycle)return 0;
    return cnt+1;
}

int main(){macos;

    cin >> n >> st;
    forr(i,0,n){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(st,-1);
    cout << node << endll << mx;

    return 0;
}