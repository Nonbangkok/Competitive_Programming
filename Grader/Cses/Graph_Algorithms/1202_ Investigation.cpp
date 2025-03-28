#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int v;
    ll w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 1e5 + 10, M = 1e9 + 7;
int n,m,a,b;
ll c;
ll dis[N];
ll cnt[N],mn[N],mx[N];
bool vis[N];
vector<pair<int,ll>> adj[N];
vector<int> adj2[N];
vector<int> p;
priority_queue<Non> q;

void dfs(int u){
    if(vis[u])return;
    vis[u] = true;
    for(int v:adj2[u])dfs(v);
    p.push_back(u);
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    forr(i,2,n+1)dis[i] = 1e18;
    q.push({1,0});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();

        for(auto [v,w]:adj[u])if(dis[v]>dis[u]+w)q.push({v,dis[v]=dis[u]+w});
    }

    forr(u,1,n+1)for(auto [v,w]:adj[u])if(dis[v]==dis[u]+w)adj2[u].push_back(v);

    dfs(1);
    reverse(p.begin(),p.end());

    forr(i,2,n+1)mn[i] = 1e18;
    cnt[1] = mn[1] = mx[1] = 1;
    for(int u:p)for(int v:adj2[u]){
        cnt[v] = (cnt[v] + cnt[u]) % M;
        mx[v] = max(mx[v],mx[u] + 1);
        mn[v] = min(mn[v],mn[u] + 1);
    }

    cout << dis[n] << sp << cnt[n] << sp << mn[n]-1 << sp << mx[n]-1;

    return 0;
}