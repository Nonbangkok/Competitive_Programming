#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10, K = 1e4 + 10;
int n,k,t,a,b,c,cnt,ans = -1;
int vis[N];
vector<int> adj[N],lvl[K];

void dfs(int u){
    vis[u] = 1;
    cnt++;
    for(int v:adj[u]){
        if(vis[v]==1)cnt = 1e9;
        if(!vis[v])dfs(v);
    }
    vis[u] = 2;
}

int main(){macos;

    cin >> n >> k >> t;
    forr(i,1,n+1){
        cin >> a >> b;
        lvl[a].push_back(i);
        forr(j,0,b)cin >> c,adj[i].push_back(c);
    }

    forr(i,1,k+1){
        bool chk = true;
        for(int u:lvl[i])if(!vis[u])dfs(u);
        if(cnt<=t)ans = i;
        else break;
    }

    cout << ans;

    return 0;
}