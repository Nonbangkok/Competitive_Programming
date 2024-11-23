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
    int v;
    ll w;
    int cnt;

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
priority_queue<Non> q;
ll dis[N][6];

int main(){macos;

    forr(i,0,N)forr(j,0,6)dis[i][j]=1e9;
    int n,m,k,a,b;
    ll c;
    cin >> n >> m >> k;

    forr(i,0,m){
        cin >> a >> b >> c;a--;b--;
        adj[a].push_back({b,c});
    }

    q.push({0,0,0});
    dis[0][0]=0;
    while(!q.empty()){
        auto [node,wei,c]=q.top();
        q.pop();
        if(wei>dis[node][c])continue;

        for(auto child:adj[node]){
            if(child.w>0&&dis[child.v][c]>dis[node][c]+child.w){
                q.push({child.v,dis[child.v][c]=dis[node][c]+child.w,c});
            }
            if(child.w<=0&&k>=c+(child.w<=-100)&&dis[child.v][c+(child.w<=-100)]>dis[node][c]){
                q.push({child.v,dis[child.v][c+(child.w<=-100)]=dis[node][c],c+(child.w<=-100)});
            }
        }
    }

    ll ans=1e9;
    forr(i,0,k+1)ans=min(ans,dis[n-1][i]);
    cout << (ans==1e9?-1:ans);

    return 0;
}