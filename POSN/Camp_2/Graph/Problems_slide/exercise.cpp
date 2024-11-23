#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

//find the number of each connected component then multiply and store in ans variable

int ans=1,cnt=0;
void trvsal(vector<int> G[],bool visited[],int n,int s){
    visited[s]=true;
    for(auto i : G[s]){
        if(!visited[i]){
            trvsal(G,visited,n,i);
            cnt++;
        }
    }
}

int main() {macos;

    int n,u,v;
    cin >> n;
    vector<int> G[8];
    bool visited[8];
    memset(visited,false,sizeof(visited));
    forr(i,0,n){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    forr(i,0,8){
        if(!visited[i]){
            trvsal(G,visited,n,i);
            ans*=cnt+1;
            cnt=0;
        }
    }
    cout << ans << endll;

    return 0;
 }
