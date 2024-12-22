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
    int v,w,c,o;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

struct Graph{
    int v,w;
};

const int N = 110;
int n,m,st,des,cap,a,b;
int cost[N],dis[2][N][N],c;
vector<Graph> adj[N];
priority_queue<Non> q;

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> cost[i];
    cin >> st >> des >> cap >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    forr(i,1,n+1)forr(j,0,cap+1)dis[0][i][j] = dis[1][i][j] = 1e9;
    q.push({st,dis[0][st][0]=0,0,0});
    while(!q.empty()){
        auto [u,wei,used,oil] = q.top();
        q.pop();

        if(oil<cap&&dis[used][u][oil+1]>dis[used][u][oil]+cost[u])
            q.push({u,dis[used][u][oil+1]=dis[used][u][oil]+cost[u],used,oil+1});
        if(!used&&dis[1][u][cap]>dis[0][u][oil])
            q.push({u,dis[1][u][cap]=dis[0][u][oil],1,cap});

        for(auto [v,w]:adj[u]){
            if(oil-w>=0&&dis[used][v][oil-w]>dis[used][u][oil])
                q.push({v,dis[used][v][oil-w]=dis[used][u][oil],used,oil-w});
        }
    }

    cout << dis[1][des][cap];

    return 0;
}