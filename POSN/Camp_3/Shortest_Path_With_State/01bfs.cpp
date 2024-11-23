#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e4+10;

struct Non{
    int v,w;
};

vector<Non> adj[N];
vector<int> dis(N,1e9);
deque<int> q;

int main(){macos;

    int v,e,a,b,c;
    cin >> v >> e;

    forr(i,0,e){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int src,des;
    cin >> src >> des;

    dis[src]=0;
    q.push_back(src);

    while(!q.empty()){
        int node=q.front();
        q.pop_front();

        for(auto child:adj[node]){
            if(dis[child.v]<=dis[node]+child.w)continue;
            if(child.w)q.push_back(child.v);
            else q.push_front(child.v); 
            dis[child.v]=dis[node]+child.w;
        }
    }
    cout << dis[des];

    return 0;
}
/*
6 9
1 2 0
1 3 1
2 3 1
2 5 1
3 4 0
1 4 1
4 5 1
5 6 0
4 6 1
1 5
bigO(E)
*/