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
    int v,w,o,p;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 110;
int n,st,des,cap,m,a,b,c;
int dis[2][N][N],cost[N];
vector<pair<int,int>> adj[N];
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
        auto [u,wei,o,p] = q.top();
        q.pop();

        if(dis[p][u][o]<wei)continue;
        if(o<cap&&dis[p][u][o+1]>dis[p][u][o]+cost[u])
            q.push({u,dis[p][u][o+1]=dis[p][u][o]+cost[u],o+1,p});
        if(!p&&dis[1][u][cap]>dis[0][u][o])
            q.push({u,dis[1][u][cap]=dis[0][u][o],cap,1});

        for(auto[v,w]:adj[u])
            if(o>=w&&dis[p][v][o-w]>dis[p][u][o])q.push({v,dis[p][v][o-w]=dis[p][u][o],o-w,p});
    }

    cout << dis[1][des][cap];

    return 0;
}