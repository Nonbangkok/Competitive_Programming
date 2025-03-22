#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
vector<int> adj[(int)2e5+10];
int color[(int)2e5+10];
int n,e;
int main(){macos;

    cin >> n >> e;
    forr(i,0,e){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mx=-1;
    forr(k,1,n+1){
        forr(i,1,n+1){
            for(auto child:adj[i]){
                if(color[child]==color[i])color[child]++;
                mx=max(mx,color[child]);
            }
        }
    }
    cout << mx+1;

    return 0;
}