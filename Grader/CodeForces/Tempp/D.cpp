#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N =2e5+10;
int a[N];
vector<int> adj[N];

int dfs(int u){
    if(adj[u].empty())return a[u];
    int mn = 1e9;
    for(int v:adj[u])mn = min(mn,dfs(v));
    if(u == 1)return a[1]+mn;
    // if(a[u]<mn)mn = (max(mn-a[u],0)/2)+min(mn,a[u]);
    if(a[u]<mn)mn = ((mn+a[u])/2);
    return mn;
}

int main(){macos;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        forr(i,1,n+1)cin >> a[i];
        forr(i,2,n+1){
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        cout << dfs(1) << endll;
        forr(i,1,n+1)adj[i].clear();
    }

    return 0;
}