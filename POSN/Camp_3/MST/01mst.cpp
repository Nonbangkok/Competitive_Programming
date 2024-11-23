#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//codeforces 1242B
const int N=1e5+10;
set<int> adj[N];
set<int> remain;
vector<int> visited(N,false);
queue<int> q,tmp;
int main(){macos;

    int n,m,a,b;
    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;a--;b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int cnt=0;
    forr(i,0,n)remain.insert(i);
    forr(i,0,n){
        if(visited[i])continue;
        visited[i]=true;
        cnt++;
        remain.erase(i);
        q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto v:remain){
                if(visited[v]||adj[u].find(v)!=adj[u].end())continue;
                visited[v]=true;
                tmp.push(v);
                q.push(v);
            }

            while(!tmp.empty())remain.erase(tmp.front()),tmp.pop();
        }
    }

    cout << cnt-1;

    return 0;
}