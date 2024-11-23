#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=1e5+10;
vector<int> adj[N];
ll sum;

ll dfs(int u,int p){
    ll cnt=0;
    //cout << u << ':' << cnt+1 << sp;
    for(auto v:adj[u]){
        if(v==p)continue;
        cnt+=dfs(v,u);
    }
    sum+=cnt+1;
    return cnt+1;
}

int main(){macos;

    int n,a,b;
    ll mx=-1;
    cin >> n;
    forr(i,0,n-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    forr(i,0,n)if(adj[i].size()==1){
        sum=0;
        dfs(i,-1);
        mx=max(mx,sum);
        //cout << sum << endll;
    }
    cout << mx;

    return 0;
}