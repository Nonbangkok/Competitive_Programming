/*
TASK: Toucher
LANG: cpp
AUTHOR: Nonbangkok
CENTER: WU
*/
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
int n,m,a,b,d,e;
ll dis[N],c;
vector<tuple<int,ll,int,int>> adj[N];
priority_queue<Non> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c >> d >> e;
        adj[a].push_back({b,c,d,e});
        adj[b].push_back({a,c,d,e});
    }
    forr(i,2,n+1)dis[i] = 1e18;
    q.push({1,0});
    while(!q.empty()){
        auto [u,wei] = q.top();
        q.pop();

        if(wei>dis[u])continue;

        for(auto[v,w,st,en]:adj[u]){
            if(dis[v]>dis[u]+w){
                if(en&&st<=dis[u]+w&&dis[u]+w<=en)continue;
                q.push({v,dis[v]=dis[u]+w});
            }
        }
    }

    if(dis[n]==1e18)cout << "meme_boi2 is untouchable (for now)";
    else cout << dis[n];

    return 0;
}