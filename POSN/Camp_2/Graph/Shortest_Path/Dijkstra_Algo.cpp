#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
// BFS 

struct Non{
    int node;
    int wei;

    // bool operator in struct
    bool operator < (const Non &rhs) const{
        if(wei<rhs.wei)return true;
        return false;
    }
};

void addEdge(vector<Non> adj[],int u, int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void shortest_path(vector<Non> adj[],int src,int V){
    vector<int> dis(V,INT_MAX);
    priority_queue<Non> q; //min heap

    dis[src]=0; //set dis at src to 0
    q.push({src,0}); //<dis,node> 

    while(!q.empty()){
        int parent = q.top().node;
        int weight = q.top().wei;
        q.pop();
        for(auto child : adj[parent]){
            if(dis[child.node]>weight+child.wei){
                dis[child.node]=weight+child.wei;
                q.push({child.node,dis[child.node]});
            }
        }
    }
    forr(i,0,V){
        cout << "node :" << i << " shortest distance from src is " << dis[i] << endll;
    }
}

int main() {macos;

    int V=9;
    vector<Non> adj[V];
    addEdge(adj,0,1,4);
    addEdge(adj,0,7,8);
    addEdge(adj,1,2,8);
    addEdge(adj,1,7,11);
    addEdge(adj,2,3,7);
    addEdge(adj,2,8,2);
    addEdge(adj,2,5,4);
    addEdge(adj,3,4,9);
    addEdge(adj,3,5,14);
    addEdge(adj,4,5,10);
    addEdge(adj,5,6,2);
    addEdge(adj,6,7,1);
    addEdge(adj,6,8,6);
    addEdge(adj,7,8,7);

    shortest_path(adj,0,V);

    return 0;
 }
