#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//Supervalentine
struct Non{
    int v,w;

    bool operator < (const Non &rhs)const{
        return w<rhs.w;
    }
};

int main() {macos;

    int n,e;
    cin >> n >> e;
    vector<Non> adj[n];
    forr(i,0,e){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c-1});
        adj[b-1].push_back({a-1,c-1});
    }

    ll ans=0;
    priority_queue<Non> q;
    q.push({0,0});
    bool visited[n];
    forr(i,0,n)visited[i]=false;
    while(!q.empty()){
        int node=q.top().v;
        int wei=q.top().w;
        q.pop();
        if(visited[node])continue;
        visited[node]=true;
        ans+=wei;
        for(auto child:adj[node]){
            if(visited[child.v])continue;//use this to optimize
            q.push({child.v,child.w});
        }
    }
    cout << ans;

    return 0;
}