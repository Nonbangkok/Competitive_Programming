#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5+10;
vector<int> adj[N];
bool mark[N];
int n,a,b,ans = 0;

void dfs(int u,int p){
    for(int v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        if(!mark[u]&&!mark[v]){
            mark[u] = mark[v] = true;
            ans++;
        }
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    cout << ans;

    return 0;
}