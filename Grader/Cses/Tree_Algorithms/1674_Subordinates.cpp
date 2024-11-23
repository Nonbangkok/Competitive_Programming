#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5+10;
vector<ll> adj[N];
ll ans[N],n,temp;

ll dfs(ll u){
    ll cnt = 0;
    for(ll v:adj[u])cnt += dfs(v);
    ans[u] = cnt;
    return cnt + 1;
}

int main(){macos;

    cin >> n;
    forr(i,2,n+1){
        cin >> temp;
        adj[temp].push_back(i);
    }

    dfs(1);

    forr(i,1,n+1)cout << ans[i] << sp;

    return 0;
}