#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1010, M = N*(N+1);
int n,m,a,b,tmp;
int p[M],dis[N];
vector<pair<int,int>> adj[N];
queue<int> q;

int main(){macos;

    cin >> n >> m;
    forr(i,1,m+1){
        cin >> a >> b;
        adj[a].push_back({b,i}); 
    }
    forr(i,1,m+1)cin >> tmp,p[tmp] = i;

    dis[1] = 1e9;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto [v,i]:adj[u]){
            if(dis[v]<min(dis[u],p[i])){
                dis[v] = min(dis[u],p[i]);
                q.push(v);
            }
        }
    }

    cout << dis[n];
    
    return 0;
}