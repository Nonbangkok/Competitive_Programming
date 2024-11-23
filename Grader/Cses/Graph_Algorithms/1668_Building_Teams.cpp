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
int teams[N],n,m,a,b;
bool visited[N],chk = true;
vector<int> adj[N];
queue<int> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    forr(i,1,n+1){
        if(visited[i])continue;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v:adj[u]){
                if(teams[v]==teams[u])teams[v]++;
                if(visited[v])continue;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    forr(i,1,n+1){
        if(teams[i]+1==3){
            chk = false;
            break;
        }
    }

    if(chk)forr(i,1,n+1)cout << teams[i]+1 << sp;
    else cout << "IMPOSSIBLE";


    return 0;
}