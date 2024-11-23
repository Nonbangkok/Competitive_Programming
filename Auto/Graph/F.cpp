#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
vector<int> adj[200005];
int visited[200005],n,m,a,b,chk=0;

void trvsal(int v){
    if(v==b)chk=1;
    if(visited[v])return;
    visited[v]=true;
    for(auto i : adj[v])trvsal(i);
}

int main() {macos;

    cin >> n >> m >> a >> b;
    a--;b--;
    forr(i,0,m){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    trvsal(a);
    chk?cout << "YES":cout << "NO";

    return 0;
}