#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=8e4+10;
vector<pair<int,int>> adj[N];
vector<int>tmp;

void dfs(int u,int par){
    for(auto [v,w]:adj[u]){
        if(v==par)continue;
        dfs(v,u);
        tmp.push_back(w);
    }
}

int main(){macos;

    int n,a,b,c,st,r=0;
    cin >> n;
    forr(i,0,n){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        r+=c;
    }
    forr(i,0,n)if(adj[i].size()==1){st=i;break;}
    dfs(st,-1);
    //for(auto i:tmp)cout << i << sp;

    int l=0,m;
    while(l<r){
        m=(l+r)>>1;

        int sum=0,cnt=0;
        for(auto i:tmp){
            sum+=i;
            if(sum>=m)sum=0,cnt++;
        }

        if(cnt<3)r=m;
        else l=m+1;
    }
    cout << l-1;

    return 0;
}