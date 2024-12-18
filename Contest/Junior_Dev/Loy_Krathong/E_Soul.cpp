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

const int N = 1e5+10;
vector<Non> adj[N];
priority_queue<Non> q;
bool visited[2][N];
ll dis[2][N];
ll a,b,c,n,m,k,st,des;

void dijkstra(ll p, ll src){
    forr(i,1,n+1)dis[p][i] = 1e18;
    q.push({src,dis[p][src]=0});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();

        for(auto [v,w]:adj[u]){
            if(visited[p][v])continue;
            if(dis[p][v]>dis[p][u]+w){
                visited[p][v] = true;
                q.push({v,dis[p][v]=dis[p][u]+w});
            }
        }
    }
}

int main(){macos;

    cin >> n >> m >> st >> des >> k;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    dijkstra(0,st);
    dijkstra(1,des);

    forr(i,0,2){
        forr(j,1,n+1){
            if(dis[i][j]==1e18)cout << '-' << sp;
            else cout << dis[i][j] << sp;
        }
        cout << endll;
    }

    return 0;
}