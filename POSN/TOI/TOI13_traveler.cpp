#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//Dijkstra's Algo

struct Non{
    ll node;
    ll wei;

    bool operator < (const Non &rhs) const{
        return wei>rhs.wei;
    }
};

int main() {macos;

    int n,m,k,u,v,src,des;
    ll w;
    cin >> n >> m >> src >> des >> k;
    vector<Non> adj[n];
    forr(i,0,m){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dis(n,INT_MAX);
    priority_queue<Non> q;
    q.push({src,0});
    dis[src]=0;

    while(!q.empty()){
        ll parent = q.top().node;
        ll weight = q.top().wei;
        q.pop();

        for(auto child : adj[parent]){
            if(dis[child.node]>weight+child.wei){
                dis[child.node]=weight+child.wei;
                q.push({child.node,dis[child.node]});
            }
        }
    }

    if(dis[des]<=k){
        cout << des << sp << dis[des] << sp << 0;
    }else{

        vector<int> disb(n,INT_MAX);
        q.push({des,0});
        disb[des]=0;

        while(!q.empty()){
            int parent = q.top().node;
            int weight = q.top().wei;
            q.pop();

            for(auto child : adj[parent]){
                if(disb[child.node]>weight+child.wei){
                    disb[child.node]=weight+child.wei;
                    q.push({child.node,disb[child.node]});
                }
            }
        }
        int inx=0,mn=INT_MAX;
        forr(i,0,n){
            if(dis[i]<=k&&mn>disb[i]){
                mn=disb[i];
                inx=i;
            }
        }
        cout << inx << sp << dis[inx] << sp << mn;

        // cout << endll << endll;
        // forr(i,0,n){
        //     cout << dis[i] << sp;
        // }
        // cout << endll;
        // forr(i,0,n){
        //     cout << disb[i] << sp;
        // }
    }
    
    return 0;
}