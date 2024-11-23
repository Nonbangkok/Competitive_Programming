#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=101;

struct Non{
    int v,w,oil,used;

    bool operator <(const Non &rhs)const{
        return w>rhs.w;
    }
};

struct path{
    int v,w;
};

priority_queue<Non> q;
vector<path> adj[N];
vector<int> value(N);
int cost[N][N][2];

int main(){macos;

    forr(i,0,N)forr(j,0,N)forr(k,0,2)cost[i][j][k]=1e9;
    int n,e,tmp,src,des,fuel,a,b,c;
    cin >> n;
    forr(i,0,n)cin >> value[i];
    cin >> src >> des >> fuel >> e;
    src--;des--;

    forr(i,0,e){
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    q.push({src,0,0,0});
    cost[src][0][0]=0;
    while(!q.empty()){
        auto [node,c,oil,used]=q.top();
        q.pop();

        if(cost[node][oil][used]<c)continue;

        if(!used&&cost[node][fuel][1]>cost[node][oil][used]){
            q.push({node,cost[node][fuel][1]=cost[node][oil][used],fuel,1});
        }
        if(oil<fuel&&cost[node][oil+1][used]>cost[node][oil][used]+value[node]){
            q.push({node,cost[node][oil+1][used]=cost[node][oil][used]+value[node],oil+1,used});
        }

        for(auto [v,w]:adj[node]){
            if(oil>=w&&cost[v][oil-w][used]>cost[node][oil][used]){
                q.push({v,cost[v][oil-w][used]=cost[node][oil][used],oil-w,used});
            }
        }
    }
    cout << cost[des][fuel][1];

    return 0;
}