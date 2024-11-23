#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int v,w;

    bool operator <(const Non &rhs)const{
        return w>rhs.w;
    }
};

int main(){macos;

    int n,m,d1,d2,a,b,c;
    cin >> n >> m >> d1 >> d2;
    d1--;d2--;
    vector<Non> adj[n];
    forr(i,0,m){
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    priority_queue<Non> q;

    int dis1[n];
    forr(i,0,n)dis1[i]=1e9;
    dis1[d1]=0;
    q.push({d1,0});
    while(!q.empty()){
        auto [node,w]=q.top();
        q.pop();

        for(auto child:adj[node]){
            if(dis1[child.v]>dis1[node]+child.w){
                dis1[child.v]=dis1[node]+child.w;
                q.push({child.v,dis1[child.v]});
            }
        }
    }

    int dis2[n];
    forr(i,0,n)dis2[i]=1e9;
    dis2[d2]=0;
    q.push({d2,0});
    while(!q.empty()){
        auto [node,w]=q.top();
        q.pop();

        for(auto child:adj[node]){
            if(dis2[child.v]>dis2[node]+child.w){
                dis2[child.v]=dis2[node]+child.w;
                q.push({child.v,dis2[child.v]});
            }
        }
    }

    forr(i,0,n)cout << dis1[i] << sp << dis2[i] << endll;

    return 0;
}