#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=20000;
struct Non{
    int v,w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

vector<Non> adj[N];
vector<int> des,par;
vector<int> dis(N,1e9);
vector<bool> visited(N,false);
priority_queue<Non> q;
set<pair<int,int>> ans;

void findpar(int x){
    if(par[x]==x)return;
    ans.insert({min(x,par[x]),max(x,par[x])});
    findpar(par[x]);
}

int main(){macos;

    int n,m,k,src,a,b,c;
    cin >> n >> m >> k >> src;

    forr(i,0,k){
        cin >> a;
        des.push_back(a);
    }

    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dis[src]=0;
    q.push({src,0});
    forr(i,0,n)par.push_back(i);
    while(!q.empty()){
        int node=q.top().v;
        q.pop();

        if(visited[node])continue;
        visited[node]=true;

        for(auto child:adj[node]){
            if(dis[child.v]>dis[node]+child.w){
                dis[child.v]=dis[node]+child.w;
                par[child.v]=node;
                q.push({child.v,dis[child.v]});
            }
        }
    }

    forr(i,0,k){
        cout << dis[des[i]] << sp;
        findpar(des[i]);
    }
    cout << endll << ans.size() << endll;
    for(auto i:ans)cout << i.first << sp << i.second << endll;

    return 0;
}