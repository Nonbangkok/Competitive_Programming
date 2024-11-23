#include <iostream>
#include <vector>
#include <tuple>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<pair<int,int>>>& graph,vector<tuple<int,int,int>>& allEdges,int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
    allEdges.emplace_back(make_tuple(u,v,w));
}

bool comp(const tuple<int,int,int>& a, const tuple<int,int,int>& b){
    return get<2>(a) < get<2>(b);
}

int find(vector<int>& parent, int x){
    if(parent[x]!=x) parent[x] = find(parent,parent[x]);
    return parent[x];
}

void union_set(vector<int>& parent, vector<int>& rank, int x, int y){
    int rootX=find(parent,x);
    int rootY=find(parent,y);

    if(rootX==rootY)return; // occurs loop
    if(rank[rootX]>rank[rootY])parent[rootY] = rootX;//merge the parent to bigger parent
    else{
        parent[rootX] = rootY;
        if(rank[rootX]==rank[rootY])rank[rootY]++;
    }
}

// kruskal must have all edges to use this algo
vector<tuple<int,int,int>> kruskal(vector<vector<pair<int,int>>>& graph,vector<tuple<int,int,int>>& allEdges){
    vector<int> parent(graph.size());
    for(int i=0;i<parent.size();i++)parent[i]=i;
    vector<int> rank(graph.size());//special component to make find parent faster
    vector<tuple<int,int,int>> result;

    sort(allEdges.begin(),allEdges.end(),comp);//sort with weight

    for(auto t : allEdges){
        int u = get<0>(t);
        int v = get<1>(t);
        int w = get<2>(t);

        if(find(parent,u)!=find(parent,v)){
            result.emplace_back(make_tuple(u,v,w));
            union_set(parent,rank,u,v);
        }
    }
    return result;
}


vector<tuple<int,int,int>> prim(vector<vector<pair<int,int>>>& graph,int start){
    vector<int> parent(graph.size(),-1);
    vector<int> key(graph.size(),INT_MAX);
    vector<bool> visited(graph.size(),false);
    vector<tuple<int,int,int>> result;

    key[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    
    while(!q.empty()){
        int v = q.top().second;
        q.pop();

        if(!visited[v]&&parent[v]!=-1){
            result.emplace_back(make_tuple(parent[v],v,key[v]));
            visited[v]=true;
        }

        for(auto child : graph[v]){
            int node = child.first;
            int wei = child.second;

            if(!visited[node]&&key[node]>wei){
                parent[node] = v;
                key[node]=wei;
                q.push({key[node],node});
            }
        }
    }
    return result;
}

int main()
{
    /*Let us create graph
          8    7
        1---2-------3
       /|   |\      |\
      /4|   |2\     | \9
     /  |   |  \    |  \
    0   |11 8   \4  |14 4
     \  |  /|    \  |  /
      \8| /7|6    \ | /10
       \|/  |      \|/
        7---6-------5
          1      2
    */
    int V = 9;
    int E = 14;

    // pair of vertex, weight
    vector<vector<pair<int,int>>> graph(V, vector<pair<int,int>>(V));
    // tuple of vertex,vertex,weight
    vector<tuple<int,int,int>> allEdges;

    addEdge(graph, allEdges, 0, 1, 4);
    addEdge(graph, allEdges, 0, 7, 8);
    addEdge(graph, allEdges, 1, 2, 8);
    addEdge(graph, allEdges, 1, 7, 11);
    addEdge(graph, allEdges, 2, 3, 7);
    addEdge(graph, allEdges, 2, 5, 4);
    addEdge(graph, allEdges, 2, 8, 2);
    addEdge(graph, allEdges, 3, 4, 9);
    addEdge(graph, allEdges, 3, 5, 14);
    addEdge(graph, allEdges, 4, 5, 10);
    addEdge(graph, allEdges, 5, 6, 2);
    addEdge(graph, allEdges, 6, 7, 1);
    addEdge(graph, allEdges, 6, 8, 6);
    addEdge(graph, allEdges, 7, 8, 7);

   vector<tuple<int,int,int>> res = kruskal(graph, allEdges);
   cout << "Minimum Spanning Tree using Kruskal: " << endl;
   for (tuple<int,int,int> t : res)
       cout << get<0>(t) << "-" << get<1>(t) << "," << get<2>(t) << endl;

   res = prim(graph, 0);
   cout << "Minimum Spanning Tree using Prim: " << endl;
   for (tuple<int,int,int> t : res)
       cout << get<0>(t) << "-" << get<1>(t) << "," << get<2>(t) << endl;

    return 0;
}
