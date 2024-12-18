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
vector<int> adj[N];
map<pair<int,int>,bool> check;
int vis[N],i;

int dfs(int u){
    int mx=u;
    vis[u]=i;
    if(u>=1){
        int v=u-1;
        if(vis[v]!=i)mx=max(mx,dfs(v));
    }
    for(auto v:adj[u]){
        if(vis[v]==i||check[{u,v}]==1)continue;
        mx=max(mx,dfs(v));
    }
    return mx;
}

int main(){macos;

    int n,q,t,x,y,z;
    cin >> n >> q;

    for(i=0;i<q;++i){
        cin >> t;
        if(t==1){
            cin >> x >> y;
            check[{x,y}]=0;
            adj[x].push_back(y);
        }else if(t==2){
            cin >> z;
            cout << dfs(z) << endll;
        }else{
            cin >> x >> y;
            check[{x,y}]=1;
        }
    }

    return 0;
}