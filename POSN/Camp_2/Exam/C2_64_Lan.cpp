#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=5000;
vector<int> adj[N];
bool visited[N];
int cnt;

void dfs(int node){
    if(visited[node])return;
    visited[node]=true;
    cnt++;
    for(auto child:adj[node]){
        dfs(child);
    }
}

int main() {macos;

    int n,a,b,e,mx=-1,cnt2=0;;
    cin >> n >> e;
    forr(i,0,e){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    forr(i,0,n){
        cnt=0;
        if(!visited[i]){
            dfs(i);
            cnt2++;
        }
        mx=max(mx,cnt);
    }
    cout << cnt2 << endll << mx;

    return 0;
}