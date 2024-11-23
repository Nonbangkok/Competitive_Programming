#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int dis[5001][101];

struct heap{
    int v,w,used;

    bool operator <(const heap &rhs)const{
        return w>rhs.w;
    }
};

struct Non{
    int v,w;
};

int main() {macos;

    priority_queue<heap> q;
    int t,n,m,k,u,v,w;
    cin >> t;

    while(t--){
        cin >> n >> m >> k;
        vector<Non> adj[n];
        forr(i,0,m){
            cin >> u >> v >> w;
            u--;v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        forr(i,0,n)forr(j,0,k+1)dis[i][j]=1e9;
        dis[0][0]=0;
        q.push({0,0,0});
        while(!q.empty()){
            int node=q.top().v,used=q.top().used;
            q.pop();
            for(auto child:adj[node]){
                if(dis[child.v][used]>dis[node][used]+child.w){
                    dis[child.v][used]=dis[node][used]+child.w;
                    q.push({child.v,dis[child.v][used],used});
                }
                if(used+1<=k&&dis[child.v][used+1]>dis[node][used]+child.w/2){
                    dis[child.v][used+1]=dis[node][used]+child.w/2;
                    q.push({child.v,dis[child.v][used+1],used+1});
                }
            }
        }
        int mx=-1,mn=1e9;
        forr(i,0,k+1){
            mx=max(mx, dis[n-1][i]);
            mn=min(mn, dis[n-1][i]);
        }
        cout << mx-mn << endll;
        forr(i,0,n)adj[i].clear();
    }

    return 0;
}