#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int n,q,x,y,z;
int ans[N];
bool a[N];
set<pair<int,int>> dis[N];
vector<pair<int,int>> adj[N];

void dfs(int u, int p, int w1){
    for(auto[v,w]:adj[u]){
        if(v==p||a[v])continue;
        auto it = dis[u].lower_bound(make_pair(v,0));
        if(it==dis[u].end()||it->first!=v||it->second<w1+w){
            if(it!=dis[u].end()&&it->first==v)dis[u].erase(it);
            dis[u].insert({v,w1+w});
            dfs(v,u,w1+w);
        }
    }
}

int main(){macos;

    cin >> n >> q;
    forr(i,0,n)cin >> a[i];
    forr(i,0,n-1){
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    forr(i,0,n)if(a[i])dfs(i,i,0LL);

    forr(i,0,n)for(auto[j,w]:dis[i])ans[j] = max(ans[j],w);

    while(q--){
        cin >> x;
        cout << ans[x] << endll;
    }

    return 0;
}