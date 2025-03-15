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
    ll v,w,c;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 1e5+10;
ll dis[N][2];
ll n,m,k,t,q,a,b,c,x;
vector<pair<ll,ll>> adj[N];
priority_queue<Non> pq;

int main(){macos;

    cin >> n >> m >> k >> t >> q;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    forr(i,0,n)dis[i][0] = dis[i][1] = 1e18;
    pq.push({0,dis[0][0]=0,0});
    while(!pq.empty()){
        auto [u,wei,s] = pq.top();
        pq.pop();

        if(wei>dis[u][s])continue;

        for(auto [v,w]:adj[u]){
            if(dis[v][s]>dis[u][s]+w)pq.push({v,dis[v][s]=dis[u][s]+w,s});
            if(k&&!s&&dis[v][1]>dis[u][s]+t)pq.push({v,dis[v][1]=dis[u][s]+t,1});
        }
    }

    while(q--){
        cin >> x;
        cout << min(dis[x][0],dis[x][1]) << endll;
    }

    return 0;
}