#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll dis[2001][2001];

struct Non{
    int v;
    ll w;
    int d;

    bool operator < (const Non &rhs)const {
        if(w!=rhs.w) return w>rhs.w;
        else return v>rhs.v;
    }
};

int main() {macos;

    int n,e,src,des;
    cin >> n >> src >> des >> e;
    vector<Non> adj[n];

    forr(i,0,e){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    ll mndis=1e18;
    int mncnt=1e9;
    priority_queue<Non> q;
    q.push({src,0,0});
    forr(i,0,n)forr(j,0,n)dis[i][j]=1e18;
    dis[src][0]=0;
    while(!q.empty()){
        auto [node,wei,cnt]=q.top();
        q.pop();

        if(wei>dis[node][cnt])continue;

        if(node==des){
            mndis=min(mndis,wei);
            mncnt=min(mncnt,cnt);
        }

        for(auto child:adj[node]){
            if(cnt+1<n&&(mncnt>cnt+1||mndis>dis[node][cnt]+child.w)&&dis[child.v][cnt+1]>dis[node][cnt]+child.w){
                dis[child.v][cnt+1]=dis[node][cnt]+child.w;
                q.push({child.v,dis[child.v][cnt+1],cnt+1});
            }
        }
    }

    // forr(i,0,n){
    //     forr(j,1,n){
    //         if(dis[i][j]==1e18) cout << setw(2) << 0 << sp;
    //         else cout << setw(2) << dis[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    int t;
    cin >> t;
    while(t--){
        ll x,mn=1e18;
        cin >> x;
        for(ll i=0;i<n;i++)mn=min(mn,dis[des][i]+(i-1)*x);
        cout << mn << sp;
    }
    
    return 0;
}