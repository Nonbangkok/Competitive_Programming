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

    bool operator <(const Non &rhs)const{
        return w>rhs.w;
    }
};

int main(){macos;

    int n,e,src,des,a,b,c;
    cin >> n >> e >> src >> des;
    vector<Non> adj[n];
    forr(i,0,e){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    priority_queue<Non> q;
    int dis[n];
    forr(i,0,n)dis[i]=1e9;
    dis[src]=0;
    q.push({src,0});
    while(!q.empty()){
        auto [node,w]=q.top();
        q.pop();

        for(auto child:adj[node]){
            if(dis[child.v]>dis[node]+child.w){
                dis[child.v]=dis[node]+child.w;
                q.push({child.v,dis[child.v]});
            }
        }
    }
    cout<< dis[des];


    return 0;
}