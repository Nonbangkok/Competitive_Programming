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
    int u;
    ll w;

    bool operator < (const Non &rhs)const{
        return w>rhs.w;
    }
};

const int N=1e5+10;
ll dis[N];
bool visited[N];
vector<Non> adj[n+1];
priority_queue<Non> q;

int main() {macos;

    int n,m;
    cin >> n >> m;
    forr(i,2,n+1)dis[i]=LLONG_MAX;
    forr(i,0,m){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    q.push({1,0});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(visited[u])continue;
        visited[u]=true;
        for(auto v:adj[u]){
            if(dis[v.u]>dis[u]+v.w){
                dis[v.u]=dis[u]+v.w;
                q.push({v.u,dis[v.u]});
            }
        }
    }
    forr(i,1,n+1)cout << dis[i] << sp;

    return 0;
}