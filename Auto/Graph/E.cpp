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
    set<int> adj[n+1];
    forr(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int chk;
    forr(i,1,n+1){
        chk=0;
        if(adj[i].size()!=n-1){
            chk=1;
            break;
        }
    }
    chk?cout << "NO":cout << "YES";

    return 0;
}