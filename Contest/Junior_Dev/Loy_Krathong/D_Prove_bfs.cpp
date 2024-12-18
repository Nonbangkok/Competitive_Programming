#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e4+10;
vector<pair<ll,ll>> adj[N];
queue<pair<ll,ll>> q;
ll dis[N];
ll n,m,x,y,d,a,b,c,st,dest,ans;

int main(){macos;

    cin >> n >> m >> x >> y >> d;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin >> st >> dest;

    forr(i,1,n+1)dis[i] = -1;
    q.push({st,0LL});
    dis[st] = LLONG_MAX;
    while(!q.empty()){
        auto [u,depth] = q.front();
        q.pop();

        for(auto [v,w]:adj[u]){
            if(x-depth*y<w)continue;
            if(dis[v]<min(dis[u],((x-depth*y)-w)/d)){
                dis[v] = max(dis[v],min(dis[u],((x-depth*y)-w)/d));
                q.push({v,depth+1});
            }
        }
    }

    if(dis[dest]==-1)cout << "Simp";
    else cout << dis[dest];

    return 0;
}