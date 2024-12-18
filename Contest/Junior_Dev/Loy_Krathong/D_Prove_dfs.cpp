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
bool visited[N];
ll n,m,x,y,d,a,b,c,st,dest,ans;

void dfs(ll u, ll depth, ll mn){
    if(u==dest){
        ans = max(ans,mn);
        return;
    }
    visited[u] = true;

    for(auto [v,w]:adj[u]){
        if(x-depth*y<w)continue;
        if(!visited[v])dfs(v,depth+1,min(mn,((x-depth*y)-w)/d));
    }
    visited[u] = false;
}

int main(){macos;

    cin >> n >> m >> x >> y >> d;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin >> st >> dest;

    dfs(st,0LL,LLONG_MAX);

    cout << ans;

    return 0;
}