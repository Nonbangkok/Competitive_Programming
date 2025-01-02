#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    ll u,v,w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        else if(u!=rhs.u)return u<rhs.u;
        return v<rhs.v;
    }
};

const int N = 1e5 + 10;
ll n,m,k,a,b,c,cnt,ans;
ll p[N];
vector<Non> edges;

ll fp(ll x){
    if(p[x]!=x)p[x] = fp(p[x]);
    return p[x];
}

int main(){macos;

    cin >> n >> m >> k;
    forr(i,0,m){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    forr(i,1,n+1)p[i] = i;
    sort(edges.begin(),edges.end());

    cnt = n;
    for(auto[u,v,w]:edges){
        if(cnt<=k)break;
        if(fp(u)==fp(v))continue;
        p[fp(v)] = fp(u);
        cnt--;
        ans = w;
    }

    if(cnt<=k)cout << ans;
    else cout << "DEADLY SIN";

    return 0;
}