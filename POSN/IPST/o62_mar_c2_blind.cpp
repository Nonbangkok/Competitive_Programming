#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e4 + 10;
int n,w;
int p[N],indeg[N];
vector<tuple<int,int,int,int>> edges;
vector<int> adj[N],ans[N];
vector<int> seq;
queue<int> q;

int fp(int x){
    if(p[x]!=x)p[x] = fp(p[x]);
    return p[x];
}

int main(){macos;

    cin >> n >> w;
    forr(i,1,n+1)p[i] = i;
    forr(i,0,w){
        int t,a,b,c;
        cin >> t >> a >> b >> c;
        if(t==3){
            if(fp(a)!=fp(b))p[fp(a)] = fp(b);
            if(fp(a)!=fp(c))p[fp(a)] = fp(c);
        }else edges.push_back({t,a,b,c});
    }

    for(auto [t,a,b,c]:edges){
        a = fp(a),b = fp(b),c = fp(c);
        if(t==1){
            adj[b].push_back(a);
            adj[c].push_back(a);
            indeg[a] += 2;
        }else{
            adj[a].push_back(b),indeg[b]++;
            adj[a].push_back(c),indeg[c]++;
        }
    }

    forr(i,1,n+1)ans[fp(i)].push_back(i);
    forr(i,1,n+1)if(!indeg[i]&&fp(i)==i)q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        seq.push_back(u);
        for(int v:adj[u]){
            indeg[v]--;
            if(indeg[v]==0)q.push(v);
        }
    }

    cout << seq.size() << endll;
    for(int i:seq){
        cout << ans[i].size() << sp;
        for(int j:ans[i])cout << j << sp;
        cout << endll;
    }

    return 0;
}