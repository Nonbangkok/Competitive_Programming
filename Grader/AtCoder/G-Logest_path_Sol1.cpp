#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
int n,m,mx=-1;
vector<int> adj[N];
vector<bool> visited(N,false);
vector<int> tmp;
vector<int> dp(N,0);

void dfs(int u){
    visited[u]=true;
    for(auto v:adj[u])if(!visited[v])dfs(v);
    tmp.push_back(u);
}

int main(){macos;

    cin >> n >> m;
    int a,b;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    forr(i,1,n+1)if(!visited[i])dfs(i);
    reverse(tmp.begin(),tmp.end());
    for(auto i:tmp){
        for(auto j:adj[i]){
            dp[j]=max(dp[j],dp[i]+1);
            mx=max(mx,dp[j]);
        }
    }
    cout << mx;

    return 0;
}