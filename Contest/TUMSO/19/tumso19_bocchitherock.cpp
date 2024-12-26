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

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 1e5+10;
int n,m,k,a,b;
ll c,dis[N];
vector<Non> adj[N];
priority_queue<Non> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    cin >> k;
    forr(i,0,k){
        cin >> a >> c;
        adj[a].push_back({n,c});
        adj[n].push_back({a,c});
    }

    forr(i,0,n)dis[i] = 1e18;
    q.push({n,0});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();

        for(auto [v,w]:adj[u]){
            if(dis[v]>dis[u]+w)q.push({v,dis[v]=dis[u]+w});
        }
    }

    cout << dis[0];

    return 0;
}