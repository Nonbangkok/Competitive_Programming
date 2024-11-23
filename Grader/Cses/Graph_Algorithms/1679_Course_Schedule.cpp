#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//kahn's Algo
int indeg[(int)1e5+10];
int main() {macos;

    queue<int> q;
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1],ans;
    forr(i,0,m){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    forr(i,1,n+1)if(!indeg[i])q.push(i);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto child : adj[node]){
            indeg[child]--;
            if(!indeg[child])q.push(child);
        }
    }

    if(ans.size()!=n)cout << "IMPOSSIBLE";
    else for(auto i : ans)cout << i << sp;


    return 0;
}