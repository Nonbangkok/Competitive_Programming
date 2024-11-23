#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
int n,m,mx=-1,node;
vector<int> adj[N];
vector<int> rev[N];

void dfs1(int u,int cnt){
    if(mx<cnt){
        mx=cnt;
        node=u;
    }

    for(auto v:adj[u])dfs1(v,cnt+1);
}

void dfs2(int u,int cnt){
    if(mx<cnt){
        mx=cnt;
        node=u;
    }

    for(auto v:rev[u])dfs2(v,cnt+1);
}

int main(){macos;

    int a,b;
    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    dfs1(1,0);
    mx=-1;
    dfs2(node,0);
    cout << mx;

    return 0;
}