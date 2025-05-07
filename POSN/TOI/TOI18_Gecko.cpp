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
int cnt;
const int N = 2e4 + 10;
int n,m,k,st,a,b,c;
int dis[N],gecko[N];
vector<pair<int,int>> adj[N];
vector<int> adj2[N];
priority_queue<Non> pq;

int main(){macos;

    cin >> n >> m >> k >> st;
    forr(i,0,k)cin >> gecko[i];
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    forr(i,0,n)dis[i] = 1e9;
    pq.push({st,dis[st]=0});
    while(!pq.empty()){
        auto [u,wei] = pq.top();
        pq.pop();
        if(dis[u]<wei)continue;
        for(auto[v,w]:adj[u]){
            if(dis[v]>dis[u]+w){
                pq.push({v,dis[v]=dis[u]+w});
                adj2[v].push_back(u);
                cnt++;
            }
        }
    }

    forr(i,0,k){
        cout << dis[gecko[i]] << sp;
    }
    cout << endll;
    cout << cnt;
    return 0;
}