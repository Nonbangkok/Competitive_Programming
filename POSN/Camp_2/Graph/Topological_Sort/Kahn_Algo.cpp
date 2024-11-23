#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

void TopologicalSort(vector<int> adj[],int indegree[],int V){
    queue<int> q;
    vector<int> result;

    forr(i,0,V){
        if(indegree[i]==0)q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        result.push_back(v);

        for(auto node : adj[v]){
            indegree[node]--;
            if(indegree[node]==0)q.push(node);
        }
    }

    if(result.size()!=V){
        cout << "Topological Sort doesn't exist in this graph";
    }else{
        for(auto i : result){
            cout << i << sp;
        }
    }
}

int main() {macos;

    int V=5;
    int edge,u,v;
    int indegree[V];
    memset(indegree,0,sizeof(indegree));
    vector<int> adj[V];
    
    cin >> edge;
    forr(i,0,edge){
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    TopologicalSort(adj,indegree,V);

    return 0;
}
/*
6
0 1
0 2
1 2
1 3
2 3
2 4
*/