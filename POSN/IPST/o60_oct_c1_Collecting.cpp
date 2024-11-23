#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=5e4+10;

struct Non{
    int v,w,state;

    bool operator <(const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

struct path{
    int v,w;
};

vector<path> adj[N];
vector<int> ranks(N);
priority_queue<Non> q;
int dis[N][40];

int main(){macos;

    int n,m,l,src,des,a,b,c;
    cin >> n >> m >> l >> src >> des;src--;des--;
    forr(i,0,n)cin >> ranks[i];
    forr(i,0,N)forr(j,0,40)dis[i][j]=1e9;
    forr(i,0,m){
        cin >> a >> b >> c;a--;b--;
        adj[a].push_back({b,c});
    }

    q.push({src,dis[0][0]=0,0});
    while(!q.empty()){
        auto [node,wei,k]=q.top();
        q.pop();

        if(wei>dis[node][k])continue;

        for(auto child:adj[node]){
            if(dis[child.v][k]>dis[node][k]+child.w){
                q.push({child.v,dis[child.v][k]=dis[node][k]+child.w,k});
            }
            if(k+1==ranks[child.v]&&dis[child.v][k+1]>dis[node][k]+child.w){
                q.push({child.v,dis[child.v][k+1]=dis[node][k]+child.w,k+1});
            }
        }
    }

    cout << dis[des][l];

    return 0;
}