
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=51,M=1e9+7;
vector<int> adj[N];
ll n,k;

ll dfs(int i,ll c){
    if(c == k)return 1;

    ll cnt = 0;
    for(int j :adj[i]){
        cnt += dfs(j,c+1);
        cnt %= M;
    }

    return cnt;
}

int main(){macos;

    cin >> n >> k;
    forr(i,0,n){
        forr(j,0,n){
            int tmp;
            cin >> tmp;
            if(tmp)adj[i].push_back(j);
        }
    }

    ll ans = 0LL;
    forr(i,0,n){
        ans += dfs(i,0);
        ans %= M;
    }
    cout << ans;

    // Not optimized

    return 0;
}