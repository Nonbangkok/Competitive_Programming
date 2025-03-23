#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1010, M = N*(N+1);
int n,m,a,b,tmp;
int p[M];
bitset<M> vis;
bool chk;
vector<pair<int,int>> adj[N];

void dfs(int u,int mid){
    if(chk)return;
    if(u==n)chk = true;

    for(auto [v,i]:adj[u]){
        if(vis[v])continue;
        if(p[i]<mid)continue;
        vis[v] = true;
        dfs(v,mid);
    }
}

int main(){macos;

    cin >> n >> m;
    forr(i,1,m+1){
        cin >> a >> b;
        adj[a].push_back({b,i}); 
    }
    forr(i,1,m+1)cin >> tmp,p[tmp] = i;

    int l = 0, r = m-1, mid;
    while(l<r){
        mid = (l+r) >> 1;

        forr(i,1,n+1)vis[i] = false;
        chk = false;
        dfs(1,mid);
        if(chk)l = mid + 1;
        else r = mid;
    }

    cout << l-1;

    return 0;
}