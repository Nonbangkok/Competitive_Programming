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
    ll v,w,cnt;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 2e3+10;
ll dis[N][N];
ll n,src,des,e,l,x,a,b,c,mn;
ll mndis = 1e18,mncnt = 1e18;
vector<pair<ll,ll>> adj[N];
priority_queue<Non> q;

int main(){macos;

    cin >> n >> src >> des >> e;
    forr(i,0,e){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    forr(i,0,n)forr(j,0,n)dis[i][j] = 1e18;
    q.push({src,dis[src][0]=0,0});
    while(!q.empty()){
        auto [u,wei,cnt] = q.top();
        q.pop();

        if(wei>dis[u][cnt])continue;
        if(u==des)mndis=min(mndis,wei),mncnt=min(mncnt,cnt);

        for(auto [v,w]:adj[u]){
            if((mncnt>cnt+1||mndis>dis[u][cnt]+w)&&dis[v][cnt+1]>dis[u][cnt]+w){
                q.push({v,dis[v][cnt+1]=dis[u][cnt]+w,cnt+1});
            }
        }
    }

    cin >> l;
    while(l--){
        cin >> x;
        mn = 1e18;
        forr(i,1,n)mn = min(mn,dis[des][i]+(i-1)*x);
        cout << mn << sp;
    }

    return 0;
}