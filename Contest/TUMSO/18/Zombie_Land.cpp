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
    ll v,w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 2e5+10;
ll n,m,s,e,a,b,c,t,x;
ll dis[3][N];
vector<Non> adj[N];
priority_queue<Non> q;

void dijkstra(ll k){
    while(!q.empty()){
        ll u = q.top().v;
        q.pop();

        for(auto [v,w]:adj[u]){
            if(dis[k][v]>dis[k][u]+w){
                q.push({v,dis[k][v]=dis[k][u]+w});
            }
        }
    }
}

int main(){macos;

    cin >> n >> m >> s >> e;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    forr(i,0,3)forr(j,1,n+1)dis[i][j] = 1e18;
    
    q.push({s,dis[0][s]=0});
    dijkstra(0);
    q.push({e,dis[1][e]=0});
    dijkstra(1);
    forr(i,1,n+1)if(dis[0][i]+dis[1][i]==dis[0][e])q.push({i,dis[2][i]=0});
    dijkstra(2);

    cin >> t;

    while(t--){
        cin >> x;
        cout << dis[2][x] << endll;
    }

    return 0;
}