#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 4e5 + 10;
int n,m,q,a,b;
int p[N],dp[21][N],lv[N],indeg[N];
vector<int> adj[N];

void dfs(int u,int p,int l){
    dp[0][u] = p,lv[u] = l;
    for(int v:adj[u])dfs(v,u,l+1);
}

int lca(int a,int b){
    if(lv[a]<lv[b]) swap(a,b);
    forl(i,20,-1)if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    forl(i,20,-1)if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int fp(int x){
    if(p[x]!=x)p[x] = fp(p[x]);
    return p[x];
}

int main(){macos;

    cin >> n >> m >> q;
    forr(i,1,n+m+1)p[i] = i;
    forr(i,1,m+1){
        cin >> a >> b;
        a = fp(a+m),b = fp(b+m);
        if(a==b)continue;
        p[a] = i,p[b] = i;
        indeg[a]++,indeg[b]++;
        adj[i].push_back(a),adj[i].push_back(b);
    }

    forr(i,1,m+1)if(!indeg[i])dfs(i,i,1);
    forr(i,1,21)forr(j,1,n+m+1)dp[i][j] = dp[i-1][dp[i-1][j]];

    while(q--){
        cin >> a >> b;
        cout << (fp(a+m)==fp(b+m)?lca(a+m,b+m):-1) << endll;
    }

    return 0;
}