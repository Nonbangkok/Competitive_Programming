#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+200;

struct Non{
    int v,w;

    bool operator <(const Non &rhs)const{
        return w>rhs.w;
    }
};

int main(){macos;

    vector<Non> adj[N];
    vector<int> group[101];
    vector<int> cost(101);
    vector<int> dis(N,1e9);
    vector<int> visited(N,false);
    priority_queue<Non> q;

    int n,m,k,a,mx=-1;
    cin >> n;

    forr(i,0,n){
        cin >> m >> k;
        cost[i]=k;
        forr(j,0,m){
            cin >> a;
            a--;
            mx=max(mx,a);
            group[i].push_back(a);
        }
    }

    forr(i,0,n){
        for(auto node:group[i]){
            adj[mx+i+1].push_back({node,cost[i]});
            adj[node].push_back({mx+i+1,0});
        }
    }

    int src,des;
    cin >> src >> des;
    src--;des--;
    q.push({src,0});
    dis[src]=0;

    while(!q.empty()){
        int node=q.top().v;
        q.pop();

        visited[node]=true;

        for(auto child:adj[node]){
            if(!visited[child.v]&&dis[child.v]>dis[node]+child.w){
                dis[child.v]=dis[node]+child.w;
                q.push({child.v,dis[child.v]});
            }
        }
    }

    cout << dis[des];

    return 0;
}