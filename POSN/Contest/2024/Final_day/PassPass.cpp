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

    bool operator < (const Non &rhs) const{
        return w>rhs.w;
    }
};

int par[1000];
int findpar(int x){
    if(par[x]!=x)return par[x]=findpar(par[x]);
    return par[x];
}

int main(){macos;

    int n,e,s,t,u,v,a,b,c;
    cin >> n >> e >> s >> t >> u >> v;
    s--;t--;u--;v--;
    forr(i,0,n)par[i]=i;
    vector<Non> adj[n];
    forr(i,0,e){
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int dis[n];
    forr(i,0,n)dis[i]=1e9;
    dis[s]=0;
    priority_queue<Non> q;
    q.push({s,0});
    while(!q.empty()){
        auto [node,w]=q.top();
        q.pop();

        for(auto child:adj[node]){
            if(dis[child.v]>dis[node]+child.w){
                dis[child.v]=dis[node]+child.w;
                q.push({child.v,dis[child.v]});
                par[child.v]=node;
            }
        }
    }
    vector<int> ans;
    int tmp=v;
    while(u!=tmp){
        tmp=par[tmp];
        ans.push_back(tmp);
    }
    forr(i,0,n)cout << i+1 << sp << par[i]+1 << sp << endll; 
    //not finished

    return 0;
}