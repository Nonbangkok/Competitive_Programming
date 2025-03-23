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
    int u;
    ll w;
    int r;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return r>rhs.r;
    }
};

const int N = 1e5 + 10;
int n,m,k,a,b;
ll c;
ll dis[N][10];
vector<pair<int,ll>> adj[N];
vector<ll> ans;
priority_queue<Non> q;

int findmn(int v){
    ll mx = 0;
    int idx = 0;
    forr(i,0,10){
        if(mx < dis[v][i]){
            mx = dis[v][i];
            idx = i;
        }
    }
    return idx;
}

int32_t main(){macos;

    cin >> n >> m >> k;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    forr(i,1,n+1)forr(j,0,10)dis[i][j] = 1e18;
    q.push({1,dis[1][0]=0,0});
    while(!q.empty()){
        auto [u,wei,rank] = q.top();
        q.pop();

        if(wei>dis[u][rank])continue;

        for(auto [v,w]:adj[u]){
            int rank_v = findmn(v);
            if(dis[v][rank_v]>dis[u][rank]+w){
                q.push({v,dis[v][rank_v]=dis[u][rank]+w,rank_v});
            }
        }
    }

    forr(i,0,10)ans.push_back(dis[n][i]);
    sort(ans.begin(),ans.end());
    forr(i,0,k)cout << ans[i] << sp;

    return 0;
}