#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int v,w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v<rhs.v;
    }
};

int main() {macos;

    int n,e,a,b,c,src,des,souv,ans=0;
    cin >> n >> e >> src >> des >> souv;
    src--;des--;souv--;
    vector<Non> adj[n];
    forr(i,0,e){
        cin >> a >> b >> c;
        a--;b--;
        adj[b].push_back({a,c});
        adj[a].push_back({b,c});
    }

    vector<int> dist(n);
    forr(i,0,n)dist[i]=INT_MAX;
    priority_queue<Non> q;
    dist[src]=0;
    q.push({src,0});
    while(!q.empty()){
        int parent=q.top().v;
        int wei =q.top().w;
        q.pop();

        for(auto child : adj[parent]){
            if(dist[child.v]>wei+child.w){
                dist[child.v]=wei+child.w;
                q.push({child.v,dist[child.v]});
            }
        }
    }
    ans+=dist[souv];

    forr(i,0,n)dist[i]=INT_MAX;
    dist[souv]=0;
    q.push({souv,0});
    while(!q.empty()){
        int parent=q.top().v;
        int wei =q.top().w;
        q.pop();

        for(auto child : adj[parent]){
            if(dist[child.v]>wei+child.w){
                dist[child.v]=wei+child.w;
                q.push({child.v,dist[child.v]});
            }
        }
    }
    cout << ans+dist[des];

    return 0;
}