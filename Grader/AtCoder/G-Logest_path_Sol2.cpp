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
vector<int> dp(N,0);

int dfs(int u){
    if(dp[u])return dp[u];

    int longest=0;
    for(auto v:adj[u])longest=max(longest,dfs(v));

    return dp[u]=longest+1;
}

int main(){macos;

    cin >> n >> m;
    int a,b;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int ans=0;
    forr(i,1,n+1)ans=max(ans,dfs(i));
    cout << ans-1;

    return 0;
}