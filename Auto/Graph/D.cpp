#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    forr(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    forr(i,1,n+1){
        sort(adj[i].begin(),adj[i].end());
        for(auto parent : adj[i]){
            cout << parent << sp;
        }
        cout << endll;
    }

    return 0;
}