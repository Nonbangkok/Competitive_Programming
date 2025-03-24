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
    int s;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 1e5 + 10;
int n,m,a,b;
ll dis[2][N],c;
vector<pair<int,ll>> adj[N];
priority_queue<Non> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    forr(i,1,n+1)dis[0][i] = dis[1][i] = 1e18;
    q.push({1,dis[0][1]=0,0});
    while(!q.empty()){
        auto [u,wei,s] = q.top();
        q.pop();

        if(wei>dis[s][u])continue;

        for(auto [v,w]:adj[u]){
            if(dis[s][v]>dis[s][u]+w)q.push({v,dis[s][v]=dis[s][u]+w,s});
            if(!s&&dis[1][v]>dis[s][u]+w/2)q.push({v,dis[1][v]=dis[s][u]+w/2,1});
        }
    }

    cout << dis[1][n];

    return 0;
}