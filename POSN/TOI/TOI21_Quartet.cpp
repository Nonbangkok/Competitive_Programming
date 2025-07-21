#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
#define int long long
using namespace std;

const int N = 2e5 + 10 , M = 1e9 + 7;
int n,m,a,b;
int ans;
int sz[N];
vector<int> adj[N],cnt[N];

void dfs(int u,int p){
    sz[u] = (u<=n);
    for(auto v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        cnt[u].push_back(sz[v]);
        sz[u] += sz[v];
    }
    cnt[u].push_back(n-sz[u]);
}

int32_t main(){macos;

    cin >> n >> m;
    forr(i,0,n+m-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);

    forr(u,n+1,n+m+1){
        int mx = cnt[u].size();
        forr(i,0,mx)forr(j,i+1,mx)forr(k,j+1,mx)forr(l,k+1,mx){
            ans += (cnt[u][i]*cnt[u][j]*cnt[u][k]*cnt[u][l]) % M;
            ans %= M;
        }
    }
    
    cout << ans;

    return 0;
}