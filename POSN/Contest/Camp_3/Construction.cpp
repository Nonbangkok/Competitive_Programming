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
    int p;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 1e5 + 10;
int n,a,b,c,st,des,mx;
ll x[N],dis[2][N];
char ch,st1,des1;
vector<tuple<int,ll,int>> adj[2][N];
priority_queue<Non> q;

// void dfs(int u, int pa, int p, int l){
//     if(u==st&&p==!(st1-'A'))mx = max(mx,l);
//     cout << u << sp << pa << sp << p << sp << l << endll;
//     cout << endll;
//     for(auto[v,w,np]:adj[!p][u]){
//         // cout << v << sp << w << sp << np << endll;
//         // cout << dis[p][u] << sp << dis[np][v] << sp << x[u] << endll;
//         if(v==pa||dis[np][v]+x[u]!=dis[!p][u])continue;
//         dfs(v,u,np,l+1);
//     }
// }

// void dfs(int u, int pa, int p, int l){
//     if(u==des&&p==des1-'A')mx = max(mx,l);
//     cout << u << sp << pa << sp << p << sp << l << endll;
//     cout << endll;
//     for(auto[v,w,np]:adj[p][u]){
//         // cout << v << sp << w << sp << np << endll;
//         cout << dis[p][u] << sp << dis[!np][v] << sp << x[u] << endll;
//         if(v==pa||dis[!np][v]!=dis[p][u]+x[u])continue;
//         dfs(v,u,!np,l+1);
//     }
// }

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> x[i];
    cin >> st >> st1 >> des >> des1;

    forr(i,1,n+1){
        cin >> a;
        forr(j,1,a+1){
            cin >> b >> ch;
            adj[ch-'A'][b].push_back({i,x[i],1});
            adj[1][i].push_back({b,x[b],ch-'A'});
        }
    }

    forr(i,0,2)forr(j,1,n+1)dis[i][j] = 1e18;
    q.push({st,dis[!(st1-'A')][st]=x[st],!(st1-'A')});
    while(!q.empty()){
        auto [u,wei,p] = q.top();
        q.pop();
        cout << u << sp << wei << sp << p << endll;
        for(auto[v,w,np]:adj[p][u]){
            if(dis[!np][v]>dis[p][u]+w){
                q.push({v,dis[!np][v]=dis[p][u]+w,!np});
            }
        }
    }
    // for(auto[v,w,np]:adj[1][3])cout << v << sp << w << sp << np << endll;
    // 1 2 0
    
    cout << endll;
    // dfs(des,des,des1-'A',0);
    // dfs(st,st,!(st1-'A'),0);
    cout << dis[des1-'A'][des] << sp << mx;

    return 0;
}