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
    int node,wei;
};

void add(vector<Non> adj[],int u,int v,int w){
    adj[u].push_back({v,w});
}

void Bellman_Ford(vector<Non> adj[],int V,int src){
    vector<int> dis(V,1000000);
    dis[src]=0;

    forr(i,0,V-1){
        forr(u,0,V){
            for(auto [v,w] : adj[u]){
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                }
            }
        }
    }
    int chk=1;
    forr(u,0,V){
        for(auto child : adj[u]){
            if(dis[child.node]>dis[u]+child.wei){
                cout << "Graph contains negative weight cycle";
                chk=0;
                break;
            }
        }
        //incorrect
    }

    if(chk){
        for(auto i : dis){
            cout << i << sp;
        }
    }
}

int main() {macos;

    int V=5;
    vector<Non> adj[V];
    add(adj,0,1,-1);
    add(adj,0,2,4);
    add(adj,1,2,3);
    add(adj,1,3,2);
    add(adj,1,4,2);
    add(adj,3,2,5);
    add(adj,3,1,1);
    add(adj,4,3,-3);

    Bellman_Ford(adj,V,0);

    return 0;
}