#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=8e4+10;

struct Non{
    int v;
    ll w;
    int par,state;

    bool operator <(const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

struct path{
    int v;
    ll w;
};

vector<path> adj[N];
vector<bool> potion(N);
vector<ll> spd;
priority_queue<Non> q;
ll dis[N][9];

int main(){macos;

    int n,m,l,cap,a,b;
    ll c;
    cin >> n >> m >> l >> cap;
    forr(i,0,m){
        cin >> a >> b >> c;a--;b--;
        adj[a].push_back({b,c});
    }
    forr(i,0,l)cin >> a,potion[--a]=true;
    forr(i,0,11)if(!i)spd.push_back(1);else spd.push_back(2*spd[i-1]);
    forr(i,0,n)forr(j,0,9)dis[i][j]=1e18;

    q.push({0,dis[0][0]=0,-1,0});
    while(!q.empty()){
        auto [node,wei,p,s]=q.top();
        q.pop();
        if(node==n-1){cout << wei;return 0;}
        if(wei>dis[node][s])continue;

        for(auto child:adj[node]){
            if(dis[child.v][s]>dis[node][s]+child.w/spd[s]){
                q.push({child.v,dis[child.v][s]=dis[node][s]+child.w/spd[s],p,s});
            }
            if(potion[node]&&s+1<=cap&&node!=p&&dis[child.v][s+1]>dis[node][s]+child.w/spd[s+1]){
                q.push({child.v,dis[child.v][s+1]=dis[node][s]+child.w/spd[s+1],node,s+1});
            }
        }
    }

    return 0;
}