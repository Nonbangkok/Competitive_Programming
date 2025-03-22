#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
#define int long long
typedef long long ll;
using namespace std;

const int N = 2e5+10;

struct Non{
    int v,t;
    ll num;
};

vector<Non> adj[N];
vector<pair<ll,ll>> Points;
set<pair<ll,ll>> s;
int n,m,l,temp,a,b,c;
ll d;

ll dis(pair<ll,ll> a, pair<ll,ll> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

void dfs(int i, ll s1, ll s2){
    if(i == n)Points.push_back({s1,s2});
    for(auto [j,t,m] : adj[i]){
        if(t == 1)dfs(j,s1+m,s2);
        else dfs(j,s1,s2+m);
    }
}

int32_t main(){macos;

    cin >> n >> m >> l;
    forr(i,0,l)cin >> temp;
    forr(i,0,m){
        cin >> a >> b >> c >> d;
        adj[a].push_back({b,c,d});
    }
    
    dfs(1,0,0);

    sort(Points.begin(),Points.end());

    int j = 0, n = Points.size();
    ll ans = LLONG_MAX;
    forr(i,0,n){
        d = sqrt(ans) + 1;
        while(!s.empty() && Points[i].first-Points[j].first >= ans)s.erase({Points[j].second,Points[j].first}),j++;
        auto l = s.lower_bound({Points[i].second-d,Points[i].first});
        auto r = s.upper_bound({Points[i].second+d,Points[i].first});
        for(auto it=l;it!=r;it++)ans = min(ans,dis({Points[i].second,Points[i].first},*it));
        s.insert({Points[i].second,Points[i].first});
    }

    cout << ans;

    return 0;
}