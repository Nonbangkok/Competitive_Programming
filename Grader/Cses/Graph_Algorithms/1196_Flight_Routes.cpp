#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int v;
    ll w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 1e5 + 10;
int n,m,a,b,k;
int vis[N]; 
ll c;
vector<Non> adj[N];
priority_queue<Non> q;

int main(){macos;

    cin >> n >> m >> k;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    q.push({1,0});
    while(!q.empty()){
        auto [u,wei] = q.top();
        q.pop();
        vis[u]++;

        if(u==n){
            cout << wei << sp;
            if(vis[u]==k)return 0;
        }

        if(vis[u]>k)continue;
        for(auto [v,w]:adj[u])if(vis[v]<=k)q.push({v,wei+w});
    }

    return 0;
}