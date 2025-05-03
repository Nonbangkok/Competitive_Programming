#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 3010;
int n,m,k,a,b,c,d;
int p[N];
ll ans;
vector<tuple<ll,int,int>> edges;
vector<pair<ll,ll>> pac;

int fp(int x){
    if(p[x]!=x)p[x] = fp(p[x]);
    return p[x];
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)p[i] = i;
    forr(i,0,m){
        cin >> a >> b >> c >> d;
        if(d)p[fp(b)] = fp(a);
        else edges.push_back({c,a,b});
    }
    cin >> k;
    forr(i,0,k)cin >> a >> b,pac.push_back({b,a});

    sort(edges.begin(),edges.end());
    sort(pac.begin(),pac.end());

    for(auto[w,u,v]:edges){
        if(fp(u)==fp(v))continue;
        p[fp(v)] = fp(u);
        for(auto[price,dis]:pac)if(dis>=w){ans+=price;break;}
    }

    cout << ans;

    return 0;
}