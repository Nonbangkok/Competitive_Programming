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
int n,a,b;
ll sub[N],dis[N],sum;

void dfs(int u, int p, ll d){
    dis[1] += d;
    for(int v:adj[u]){
        if(v==p)continue;
        dfs(v,u,d+1);
        sub[u] += sub[v];
    }
    sub[u]++;
}

void dfs1(int u, int p){
    for(int v:adj[u]){
        if(v==p)continue;
        dis[v] = dis[u] + n - 2*sub[v];
        dfs1(v,u);
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0,1);
    dfs1(1,0);

    cout << *max_element(dis+1,dis+n+1);

    return 0;
}