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
    int v,w;

    bool operator < (const Non &rhs)const{
        if(w != rhs.w)return w > rhs.w;
        return v > rhs.v;
    }
};

const int N = 2e5 + 10;
int n,m,k,a,b;
int dis[N],c[N],ans[N];
vector<int> adj[N];
priority_queue<Non> q;

int main(){macos;

    cin >> n >> m >> k;
    forr(i,1,n+1)cin >> c[i];
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    forr(i,1,n+1)dis[i] = 1e9, ans[i] = 0;

    q.push({1,dis[1]=0});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();

        ans[c[u]] = max(ans[c[u]],dis[u]);
        for(int v:adj[u])if(dis[v]>dis[u]+1)q.push({v,dis[v]=dis[u]+1});
    }

    forr(i,1,k+1)cout << ans[i] << sp;

    return 0;
}