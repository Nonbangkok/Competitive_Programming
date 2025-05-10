#include "longest_path.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int longest_path(int n, const vector<vector<pair<int, int>>>& graph){
    int dis[n],indeg[n],mx = 0;
    queue<int> q;
    for(int i=0;i<n;i++)dis[i] = 0,indeg[i] = 0;
    for(int i=0;i<n;i++)for(auto [j,_]:graph[i])indeg[j]++;
    for(int i=0;i<n;i++)if(!indeg[i])q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto [v,w]:graph[u]){
            dis[v] = max(dis[v],dis[u]+w);
            mx = max(mx,dis[v]);
            if(!--indeg[v])q.push(v);
        }
    }
    return mx;
}
// cd longest_path && make && ./build/main