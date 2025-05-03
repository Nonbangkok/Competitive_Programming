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

const int N = 1e5 + 10;
int n,m,x,y,st,des,a,b;
bool vis[N];
ll dis[3][N],dp[2][N],c,ans=1e18;
vector<pair<int,ll>> adj[N];
priority_queue<Non> q;

void dijkstra(int z, int s){
    forr(i,1,n+1)dis[s][i] = 1e18;
    q.push({z,dis[s][z]=0LL});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();

        for(auto [v,w]:adj[u])
            if(dis[s][v]>dis[s][u]+w)
                q.push({v,dis[s][v]=dis[s][u]+w});
    }
}

void dfs(int u){
    if(vis[u])return;
    vis[u] = true;
    dp[0][u] = dis[1][u];
    dp[1][u] = dis[2][u];
    for(auto [v,w]:adj[u]){
        if(dis[0][v]+w!=dis[0][u])continue;
        dfs(v);
        dp[0][u] = min(dp[0][u],dp[0][v]);
        dp[1][u] = min(dp[1][u],dp[1][v]);
    }
    ans = min(ans,dp[0][u]+dis[2][u]);
    ans = min(ans,dp[1][u]+dis[1][u]);
}

int main(){macos;

    cin >> n >> m >> x >> y >> st >> des;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dijkstra(x,0);
    dijkstra(st,1);
    dijkstra(des,2);
    dfs(y);
    cout << min(dis[1][des],ans);
    
    return 0;
}