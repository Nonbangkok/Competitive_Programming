#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
int n,k,t,lvl,tmp,p,ans=-1,cnt=0;
vector<int> adj[N],level[N],visited(N);

void dfs(int u){
    if(visited[u]){
        cnt=(visited[u]==1?1e9:cnt);
        return;
    }
    cnt++;
    visited[u]=1;
    for(auto v:adj[u])dfs(v);
    visited[u]=2;
}

int main() {macos;

    cin >> n >> k >> t;
    forr(i,1,n+1){
        cin >> lvl >> tmp;
        level[lvl].push_back(i);
        forr(j,0,tmp){
            cin >> p;
            adj[i].push_back(p);
        }
    }

    forr(i,1,k+1){
        for(auto node:level[i]){
            if(!visited[node])dfs(node);
        }
        if(cnt<=t)ans=i;
        else break;
    }
    cout << ans;

    return 0;
}