#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e4+10;
vector<pair<ll,ll>> adj[N];
ll n,m,x,y,d,a,b,c,st,dest;

bool bfs(int mid){
    queue<pair<ll,ll>> q;
    bool visited[N];
    forr(i,1,n+1)visited[i] = false;

    q.push({st,0});
    visited[st] = true;
    while(!q.empty()){
        auto [u,depth] = q.front();
        q.pop();

        for(auto [v,w]:adj[u]){
            if(visited[v]||x-(depth*y)<w+mid*d)continue;
            visited[v] =  true;
            q.push({v,depth+1});
        }
    }
    return visited[dest];
}

int main(){macos;

    cin >> n >> m >> x >> y >> d;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin >> st >> dest;

    ll l=0,r=1e9,mid;
    while(l<r){
        mid = (l+r)>>1;
        if(bfs(mid))l=mid+1;
        else r=mid;
    }

    if(l)cout << l-1;
    else cout << "Simp";

    return 0;
}