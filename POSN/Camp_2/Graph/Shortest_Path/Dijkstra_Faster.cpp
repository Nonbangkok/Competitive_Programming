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
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 1e4 + 10;
int n,m,a,b,c;
int dis[N],cnt[N];
vector<Non> adj[N];
priority_queue<Non> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,n){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    q.push({0,dis[0]=0});
    while(!q.empty()){
        auto [u,wei] = q.top();
        q.pop();

        for(auto [v,w]:adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                cnt[v]++;
            }
        }
    }

    cout << dis[n-1];

    return 0;
}