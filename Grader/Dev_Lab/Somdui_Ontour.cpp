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
    ll u,w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return u>rhs.u;
    }
};

const int N = 110;
priority_queue<Non> q;
vector<Non> adj[N];
ll dis[N];

int main(){macos;

    ll n,m,a,b,c;
    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    forr(i,0,n+1)dis[i] = 1e9;
    dis[1] = 0;
    q.push({1,0});
    while(!q.empty()){
        int u = q.top().u;
        q.pop();

        for(auto [v,w]:adj[u]){
            if(dis[v]>dis[u]+w){
                q.push({v,dis[v]=dis[u]+w});
            }
        }
    }

    cout << dis[n];

    return 0;
}