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
int n,q,a,b,c;
int dp[21][N],lv[N];
vector<int> adj[N];

void dfs(int u, int p, int d){
    dp[0][u] = p, lv[u] = d;
    for(int v:adj[u])if(v!=p)dfs(v,u,d+1);
}

int lca(int a, int b){ 
    if(lv[a]<lv[b])swap(a,b);
    forl(i,20,-1)if(lv[dp[i][a]]>=lv[b])a = dp[i][a];
    if(a==b)return a;
    forl(i,20,-1)if(dp[i][a]!=dp[i][b])a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int main(){macos;

    cin >> n >> q;
    forr(i,0,n-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1,0);
    forr(i,1,21)forr(j,1,n+1)dp[i][j] = dp[i-1][dp[i-1][j]];

    while(q--){
        cin >> a >> b;
        c = lca(a,b);
        cout << lv[a] + lv[b] - 2 * lv[c] << endll;
    }

    return 0;
}