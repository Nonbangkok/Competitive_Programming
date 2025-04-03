#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
ll n,m,l,z,a,b,c,d;
vector<tuple<ll,ll,ll>> adj[N];
vector<pair<ll,ll>> Pts;
set<pair<ll,ll>> s;

void dfs(ll u, ll wa, ll wb){
    if(u==n)Pts.push_back({wa,wb});
    else for(auto [v,t,w]:adj[u]){
        if(t==1)dfs(v,wa+w,wb);
        else dfs(v,wa,wb+w);
    }
}

int main(){macos;

    cin >> n >> m >> l;
    forr(i,0,l)cin >> z;
    forr(i,0,m){
        cin >> a >> b >> c >> d;
        adj[a].push_back({b,c,d});
    }

    dfs(1,0,0);

    sort(Pts.begin(),Pts.end());

    ll j = 0, ans = LLONG_MAX;
    forr(i,0,Pts.size()){
        d = sqrt(ans) + 1;
        while(Pts[j].first-Pts[i].first>=d)s.erase({Pts[j].second,Pts[j].first}),j++;
        auto l = s.lower_bound({Pts[i].second-d,Pts[i].first});
        auto r = s.lower_bound({Pts[i].second+d,Pts[i].first});
        for(auto it=l;it!=r;it++){
            ll dx = (Pts[i].first-it->second);
            ll dy = (Pts[i].second-it->first);
            ans = min(ans,dx*dx+dy*dy);
        }
        s.insert({Pts[i].second,Pts[i].first});
    }

    cout << ans;

    return 0;
}