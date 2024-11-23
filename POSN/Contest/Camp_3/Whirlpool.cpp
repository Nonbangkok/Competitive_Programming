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
vector<ll> adj[N],rev_adj[N],dan(N),group,out_node;
vector<bool> visited(N);

void dfs(ll u){
    visited[u]=true;
    for(auto v:adj[u])if(!visited[v])dfs(v);
    out_node.push_back(u);
}

ll dfs2(ll u){
    ll sum=0;
    visited[u]=true;
    for(auto v:rev_adj[u])if(!visited[v])sum+=dfs2(v);
    return sum+dan[u];
}

int main(){macos;

    ll n,m,q,a,b,k;
    cin >> n >> m >> q;
    forr(i,0,n)cin >> dan[i];
    forr(i,0,m){
        cin >> a >> b;a--;b--;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    forr(i,0,n)if(!visited[i])dfs(i);
    forr(i,0,n)visited[i]=false;
    reverse(out_node.begin(),out_node.end());
    for(auto u:out_node)if(!visited[u])group.push_back(dfs2(u));
    sort(group.begin(),group.end());
    while(q--)cin >> k,cout << upper_bound(group.begin(),group.end(),k)-group.begin() << endll;

    return 0;
}