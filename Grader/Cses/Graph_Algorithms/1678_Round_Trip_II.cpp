#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5+10;
int par[N],visited[N],n,m,a,b,st,en;
bool chk = 0;
vector<int> adj[N],ans;

void dfs(int u){
    visited[u] = 1;
    for(int v:adj[u]){
        if(visited[v] == 0){
            par[v] = u;
            dfs(v);
            if(st)return;
        }else if(visited[v] == 1){
            st = v,en = u;
            return;
        }
    }
    visited[u] = 2;
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1;i<=n && !st;i++)if(!visited[i])dfs(i);
    if(!st){
        cout << "IMPOSSIBLE";
        return 0;
    }
    // cout << st << sp << en << endll;
    for(int u = en;u != st;u = par[u])ans.push_back(u);
    reverse(ans.begin(),ans.end());
    cout << ans.size()+2 << endll << st << sp;
    for(int i:ans)cout << i << sp;
    cout << st << sp;

    return 0;
}