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

const int N = 1e5+10;
int n,m,k,s,t,a,b,c,p;
int dis[2][N];
vector<Non> adj[2][N];
priority_queue<Non> q;

void dijkstra(int st,int s){
    q.push({st,dis[s][st] = 0});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();

        for(auto [v,w]:adj[s][u]){
            if(dis[s][v]>dis[s][u]+w)q.push({v,dis[s][v]=dis[s][u]+w});
        }
    }
}

int main(){macos;

    cin >> n >> m >> k >> s >> t;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[0][a].push_back({b,c});
        adj[1][b].push_back({a,c});
    }

    forr(i,0,2)forr(j,0,n+1)dis[i][j] = 1e9;
    dijkstra(s,0);
    dijkstra(t,1);

    while(k--){
        cin >> p;
        cout << dis[0][p]+dis[1][p] << endll;
    }

    return 0;
}