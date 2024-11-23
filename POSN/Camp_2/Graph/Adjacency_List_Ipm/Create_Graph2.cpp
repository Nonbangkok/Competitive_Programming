#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
// directed Graph with weighted
void addEdge(vector<pair<int,int>> adj[],int u, int v,int w){
    adj[u].push_back({v,w});
}

void printGraph(vector<pair<int,int>> adj[],int V){
    forr(i,0,V){
        cout << "Adjaceny list of vertex " << i << endll << "head ";
        for(auto it=adj[i].begin();it!=adj[i].end();it++){
            cout << "-> " << it->first << " With Weighted " << it->second << sp;
        }
        cout << endll;
    }
}

int main() {macos;

    int V=4;
    vector<pair<int,int>> adj[V];
    addEdge(adj,0,1,10);
    addEdge(adj,0,3,2);
    addEdge(adj,0,2,3);
    addEdge(adj,1,3,7);
    addEdge(adj,2,3,6);
    printGraph(adj,V);

    return 0;
 }
