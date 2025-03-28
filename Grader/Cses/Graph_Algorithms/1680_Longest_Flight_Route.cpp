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
int p[N],dis[N];
int n,m,a,b;
bool vis[N];
vector<int> adj[N],q,ans;

void dfs(int u){
    if(vis[u])return;
    vis[u] = true;
    for(int v:adj[u])dfs(v);
    q.push_back(u);
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);

    reverse(q.begin(),q.end());
    for(int u:q){
        for(int v:adj[u]){
            if(dis[v]<dis[u]+1){
                dis[v] = dis[u]+1;
                p[v] = u;
            }
        }
    }

    if(!p[n]){
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i=n;i!=1;i=p[i])ans.push_back(i);
    ans.push_back(1);
    reverse(ans.begin(),ans.end());

    cout << ans.size() << endll;
    for(int i:ans)cout << i << sp;

    return 0;
}