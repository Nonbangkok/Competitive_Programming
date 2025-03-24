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
    int a,b;
    ll c;
};

const int N = 2510;
int n,m,a,b;
ll dis[N],c;
bool vis[2][N];
vector<Non> edges;
vector<int> adj[2][N];

void dfs(int u, int s){
    if(vis[s][u])return;
    vis[s][u] = true;
    for(int v:adj[s][u])dfs(v,s);
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }

    forr(i,1,n+1)dis[i]=-1e18;
    dis[1] = 0;
    dfs(1,0),dfs(n,1);
    forr(k,0,n){
        for(auto [u,v,w]:edges){
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
                if(k==n-1&&vis[0][v]&&vis[1][v]){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << dis[n];

    return 0;
}
 