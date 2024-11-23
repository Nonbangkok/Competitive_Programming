#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=8e4+10,M=(1<<20);

struct Non{
    int v,w;

    bool operator <(const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return v>rhs.v;
    }
};

vector<Non> adj[M];
vector<int> dis(M,1e9),des;
priority_queue<Non> q;

int main(){macos;

    int n,m,w,a;
    cin >> n >> m;
    forr(i,0,n){
        int poi=0,drug=0;
        cin >> w;
        forr(j,0,m){
            cin >> a;
            if(a==-1)poi|=(1<<j);
            else if(a==1)drug|=(1<<j);
        }
        adj[poi].push_back({drug,w});
        des.push_back(poi);
    }

    q.push({0,dis[0]=0});
    while(!q.empty()){
        auto [node,w]=q.top();
        q.pop();
        if(dis[node]<w)continue;

        for(auto child:adj[node]){
            if(dis[child.v]>dis[node]+child.w){
                q.push({child.v,dis[child.v]=dis[node]+child.w});
            }
        }

        forr(i,0,m){
            if(node&(1<<i)&&dis[node^(1<<i)]>dis[node]){
                q.push({node^(1<<i),dis[node^(1<<i)]=dis[node]});
            }
        }

    }

    int ans=0;
    for(auto i:des)if(dis[i]!=1e9)ans=max(ans,dis[i]);
    cout << ans;

    return 0;
}
/*
3 2
1 -1 0
2 1 0
1 1 1
*/