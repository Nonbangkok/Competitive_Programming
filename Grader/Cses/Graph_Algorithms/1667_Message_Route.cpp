#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5+10;
int pre[N],n,m,a,b;
bool visited[N],chk = false;
vector<int> adj[N],ans;
queue<int> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u==n){
            int u = n;
            while(u!=1){
                ans.push_back(u);
                u = pre[u];
            }
            ans.push_back(1);
            cout << ans.size() << endll;
            reverse(ans.begin(),ans.end());
            for(int i:ans)cout << i << sp;
            return 0;
        }

        for(int v:adj[u]){
            if(visited[v])continue;
            visited[v] = true;
            pre[v] = u;
            q.push(v);
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}