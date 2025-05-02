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
int n,m;
int p[N];
ll ans;
vector<tuple<ll,int,int>> edges;

int fp(int x){
    if(p[x]!=x)p[x] = fp(p[x]);
    return p[x];
}

int main(){macos;

    cin >> n >> m;
    edges.resize(m);
    for(auto &[c,a,b]:edges)cin >> a >> b >> c;

    sort(edges.rbegin(),edges.rend());

    forr(i,1,n+1)p[i] = i;
    for(auto[w,u,v]:edges){
        if(fp(u)==fp(v))continue;
        p[fp(v)] = fp(u);
        ans += w - 1;
    }

    cout << ans;

    return 0;
}