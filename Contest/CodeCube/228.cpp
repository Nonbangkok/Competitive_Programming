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

struct Non{
    ll v,w,x;

    bool operator < (const Non &rhs)const{
        return w>rhs.w;
    }
};

ll dis[N],dis2[N];
bool visited[N],visited2[N];
priority_queue<Non> q;
vector<Non> edges;

int main() {macos;

    ll n,m,k,t;
    cin >> n >> m >> k >> t;
    vector<Non> adj[n+1];
    forr(i,0,m){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        if(c>=k)edges.push_back({a,b,c});
    }

    forr(i,2,n+1)dis[i]=INT_MAX;
    q.push({1,0});
    while(!q.empty()){
        ll node=q.top().v;
        q.pop();
        if(visited[node])continue;
        visited[node]=true;
        for(auto child:adj[node]){
            if(dis[child.v]>dis[node]+child.w){
                dis[child.v]=dis[node]+child.w;
                q.push({child.v,dis[child.v]});
            }
        }
    }

    forr(i,1,n)dis2[i]=INT_MAX;
    q.push({n,0});
    while(!q.empty()){
        ll node=q.top().v;
        q.pop();
        if(visited2[node])continue;
        visited2[node]=true;
        for(auto child:adj[node]){
            if(dis2[child.v]>dis2[node]+child.w){
                dis2[child.v]=dis2[node]+child.w;
                q.push({child.v,dis2[child.v]});
            }
        }
    }

    ll mn=dis[n];
    for(auto [u,v,w]:edges){
        mn=min(mn,min(dis[u]+dis2[v],dis2[u]+dis[v])+k);
    }

    (mn<=t)?cout << "Happy Winnie the Pooh :3" << endll << mn:cout << "No Honey TT";

    return 0;
}