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

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

const int N = 19;
int n,s,a,b,c,mx;
int poison,anti;
int dis[1<<N];
vector<Non> adj[1<<N];
vector<int> des;
priority_queue<Non> q;

int main(){macos;

    cin >> n >> s;
    forr(i,0,n){
        cin >> a;
        poison = 0, anti = 0;
        forr(j,0,s){
            cin >> b;
            if(b==1)anti |= 1 << j;
            else if(b==-1) poison |= 1 << j;
        }
        adj[poison].push_back({anti,a});
        des.push_back(poison);
    }

    forr(i,0,1<<s)dis[i] = 1e9;
    q.push({0,dis[0]=0});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();

        for(auto[v,w]:adj[u])if(dis[v]>dis[u]+w)q.push({v,dis[v]=dis[u]+w});
        forr(i,0,s){
            int v = u^(1<<i);
            if(u&(1<<i)&&dis[v]>dis[u])q.push({v,dis[v]=dis[u]});
        }
    }
    
    for(int i:des)if(dis[i]!=1e9)mx = max(mx,dis[i]);
    cout << mx;

    return 0;
}