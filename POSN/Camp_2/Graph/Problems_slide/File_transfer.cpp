#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

//i node can travel to j node if can YES else NO

int chk;
void trvsal(vector<int> G[],bool visited[],int u,int v){
    if(u==v||chk){
        chk=1;
        return;
    }
    visited[u]=true;
    for(auto i : G[u]){
        if(!visited[i]){
            trvsal(G,visited,i,v);
        }
    }
}

int main() {macos;

    int n,m,q,u,v;
    cin >> n >> m >> q;
    vector<int> G[n+1];
    bool visited[n+1];
    forr(i,0,m){
        cin >> u >> v;
        G[u].push_back(v);
    }
    forr(i,0,q){
        cin >> u >> v;
        chk=0;
        memset(visited,false,sizeof(visited));
        trvsal(G,visited,u,v);
        chk?cout << "YES" << endll: cout << "NO" << endll;
    }

    return 0;
 }
