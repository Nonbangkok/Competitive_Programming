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
int dis[N],n,a,b;

void dfs(int u, int p){
    for(int v:adj[u]){
        if(v==p)continue;
        dis[v] = dis[u] + 1;
        dfs(v,u);
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dis[1] = 0;
    dfs(1,0);

    int st = max_element(dis+1,dis+n+1)-dis;

    dis[st] = 0;
    dfs(st,0);

    cout << *max_element(dis+1,dis+n+1);

    return 0;
}