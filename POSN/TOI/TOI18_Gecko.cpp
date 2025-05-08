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
    int v,w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 2e4 + 10;
int n,m,k,st,a,b,c,cnt;
int dis[N],gecko[N],indeg[N];
bool vis[N];
vector<pair<int,int>> adj[N];
priority_queue<Non> pq;
queue<int> q;
set<int> adj2[N];

void dfs(int u, int p){
    for(auto[v,w]:adj[u]){
        if(v==p||dis[v]+w!=dis[u])continue;
        adj2[u].insert(v);
        dfs(v,u);
    }
}

int main(){macos;

    cin >> n >> m >> k >> st;
    forr(i,0,k)cin >> gecko[i];
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    forr(i,0,n)dis[i] = 1e9;
    pq.push({st,dis[st]=0});
    while(!pq.empty()){
        auto [u,wei] = pq.top();
        pq.pop();
        if(dis[u]<wei)continue;
        for(auto[v,w]:adj[u]){
            if(dis[v]>dis[u]+w){
                pq.push({v,dis[v]=dis[u]+w});
            }
        }
    }

    forr(i,0,k)cout << dis[gecko[i]] << sp,dfs(gecko[i],-1);
    forr(i,0,n){
        cnt += adj2[i].size();
        for(int j:adj2[i])indeg[j]++;
    }
    cout << endll << cnt << endll;

    forr(i,0,k)if(!indeg[gecko[i]])q.push(gecko[i]);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj2[u]){
            cout << min(u,v) << sp << max(v,u) << endll;
            if(!--indeg[v])q.push(v);
        }
    }

    return 0;
}