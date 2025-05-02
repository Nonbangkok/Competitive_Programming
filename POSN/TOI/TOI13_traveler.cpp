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

const int N = 1e4 + 10;
int n,m,st,des,a,b,x;
ll c,k,mn = 1e18;
ll dis[2][N];
vector<Non> adj[N];
priority_queue<Non> q;

void dijkstra(int st, int s){
    forr(i,0,n)dis[s][i] = 1e18;
    q.push({st,dis[s][st]=0LL});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();
        for(auto [v,w]:adj[u])
            if(dis[s][v]>dis[s][u]+w)q.push({v,dis[s][v]=dis[s][u]+w});
    }
}

int main(){macos;

    cin >> n >> m >> st >> des >> k;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dijkstra(st,0);
    if(dis[0][des]<=k){cout << des << sp << dis[0][des] << sp << 0;return 0;}
    dijkstra(des,1);
    forl(i,n-1,-1)if(i!=des&&dis[0][i]<=k&&mn>=dis[1][i])mn = dis[1][i],x = i;
    cout << x << sp << dis[0][x] << sp << mn;

    return 0;
}