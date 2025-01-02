#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 1e4+10;
ll p[N];
ll n,k,c;
ld a,b,ans=1e18;
bool visited[N];
vector<pair<ld,ld>> adj[N];

ld dis(pair<ld,ld> a,pair<ld,ld> b){
    ld x = a.first-b.first;
    ld y = a.second-b.second;
    return x*x+y*y;
}

int main(){macos;

    cin >> n >> k;
    forr(i,0,k)cin >> p[i];
    forr(i,0,n){
        cin >> a >> b >> c;
        adj[c].push_back({a,b});
    }

    forl(i,k,1){
        for(auto u:adj[i]){
            for(auto v:adj[i+1]){
                ld d = dis(u,v);
                if(d>p[u]||d>p[v])continue;
                ans = min(ans,sqrt(d));
            }
        }
    }

    cout << ans;

    //not finished

    return 0;
}