#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 8e4 + 10;
int n,a,b,cnt,st;
ll c,sum;
vector<pair<int,ll>> adj[N];
vector<int> q;

void dfs(int u, int p){
    for(auto [v,w]:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        q.push_back(w);
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        sum += c;
    }

    forr(i,0,n+1)if(adj[i].size()==1){
        dfs(i,i);
        st = i;
        break;
    }

    ll l = 0, r = sum, mid;
    while(l<r){
        mid = (l+r) >> 1;

        ll cnt = 0, sum = 0;
        forr(i,0,q.size()){
            sum += q[i];
            if(sum>=mid)cnt++,sum = 0;
        }

        if(cnt>=3)l = mid + 1;
        else r = mid;
    }
    
    cout << l-1;

    return 0;
}