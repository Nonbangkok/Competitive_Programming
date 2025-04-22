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
int n,m,a,b,mx;
int dp[N],indeg[N];
vector<int> adj[N];
queue<int> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    forr(i,1,n+1)if(!indeg[i])q.push(i);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v:adj[u]){
            indeg[v]--;
            if(!indeg[v]){
                dp[v] = dp[u] + 1;
                mx = max(mx,dp[v]);
                q.push(v);
            }
        }
    }
    
    cout << mx;

    return 0;
}