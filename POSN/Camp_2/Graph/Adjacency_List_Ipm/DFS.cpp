#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
// DFS
void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(vector<int> adj[],bool visited[],int s,int V){
    visited[s]=true;
    cout << s << sp;
    for(auto i : adj[s]){
        if(!visited[i])
        DFS(adj,visited,i,V);
    }

}

int main() {macos;

    int V=10;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,4);
    addEdge(adj,2,5);
    addEdge(adj,2,6);
    addEdge(adj,4,8);
    addEdge(adj,5,9);
    addEdge(adj,3,7);

    bool visited[V];
    memset(visited,false,sizeof(visited));
    DFS(adj,visited,0,V);

    return 0;
 }
