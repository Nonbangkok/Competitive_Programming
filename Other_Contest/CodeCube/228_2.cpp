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
    ll v,w,state;

    bool operator <(const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        else return v>rhs.v;
    }
};

struct path{ll x,y;};

priority_queue<Non> q;
vector<path> adj[N];
ll dis[N][2];

int main(){macos;

    ll n,m,k,t,a,b,c;
    cin >> n >> m >> k >> t;
    forr(i,0,n)dis[i][0]=dis[i][1]=1e9;
    forr(i,0,m){
        cin >> a >> b >> c;a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    q.push({0,dis[0][0]=0,0});
    while(!q.empty()){
        auto[u,x,s]=q.top();
        q.pop();
        if(dis[u][s]<x)continue;

        for(auto [v,w]:adj[u]){
            if(dis[v][s]>dis[u][s]+w){
                q.push({v,dis[v][s]=dis[u][s]+w,s});
            }
            if(!s&&dis[v][1]>dis[u][s]+k){
                q.push({v,dis[v][1]=dis[u][s]+k,1});
            }
        }
    }
    ll ans=min(dis[n-1][0],dis[n-1][1]);
    if(ans<=t)cout << "Happy Winnie the Pooh :3" << endll << ans;
    else cout << "No Honey TT";

    return 0;
}