#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//no detect cycle in graph

stack<int> st;
void trvsal(vector<int> adj[],int v,bool visited[]){
    visited[v] = true;
    for(auto node : adj[v]){
        if(!visited[node]) trvsal(adj,node,visited);
    }
    st.push(v);
}

void TopologicalSort(vector<int> adj[],int V){
    bool visited[V];
    memset(visited,false,sizeof(visited));

    forr(i,0,V){
        if(!visited[i]) trvsal(adj,i,visited);
    }
    
    //for print
    while(!st.empty()){
        cout << st.top() << sp;
        st.pop();
    }
    
}

int main() {macos;

    int V=6;
    vector<int> adj[V];

    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);

    TopologicalSort(adj,V);

    return 0;
}