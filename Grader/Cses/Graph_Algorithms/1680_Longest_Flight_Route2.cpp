#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int n,m,a,b;
int indeg[N],mx[N],p[N];
vector<int> adj[N],ans;
queue<int> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }    
    forr(i,1,n+1)if(!indeg[i])q.push(i);

    mx[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v:adj[u]){
            indeg[v]--;
            if(mx[u]&&mx[v]<mx[u]+1)mx[v] = mx[u] + 1,p[v] = u;
            if(!indeg[v])q.push(v);
        }
    }

    if(!mx[n]){cout << "IMPOSSIBLE";return 0;}
    for(int u=n;u!=1;u=p[u])ans.push_back(u);
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endll;
    for(int i:ans)cout << i << sp;

    return 0;
}