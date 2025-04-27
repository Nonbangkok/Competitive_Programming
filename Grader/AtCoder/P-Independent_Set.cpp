#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10, M = 1e9 + 7;
int n,a,b;
ll dp[2][N];
vector<int> adj[N];

void dfs(int u, int p){
    dp[0][u] = dp[1][u] = 1;

    for(int v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        dp[0][u] *= dp[0][v] + dp[1][v];
        dp[0][u] %= M;
        dp[1][u] *= dp[0][v];
        dp[1][u] %= M;
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);
    cout << (dp[0][1] + dp[1][1]) % M;

    return 0;
}