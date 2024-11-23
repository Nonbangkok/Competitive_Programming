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
    int u,v;
    ll w;

    bool operator < (const Non &rhs)const{
        return w<rhs.w;
    }
};

int par[200001];
int findpar(int x){
    if(par[x]!=x)par[x]=findpar(par[x]);
    return par[x];
}

int main(){macos;

    vector<Non> edges;
    int n,e,a,b,k;
    ll c,ans=0;
    cin >> n >> e;
    forr(i,0,n)par[i]=i;
    forr(i,0,e){
        cin >> a >> b >> c;
        a--;b--;
        edges.push_back({a,b,c});
    }
    cin >> k;
    forr(i,0,k){
        cin >> a >> b >> c;
        a--;b--;
        par[findpar(b)]=par[findpar(a)];
        ans+=c;
    }
    sort(edges.begin(),edges.end());

    forr(i,0,e){
        auto [u,v,w]=edges[i];
        if(findpar(u)==findpar(v))continue;
        par[findpar(v)]=par[findpar(u)];
        ans+=w;
    }
    cout << ans;

    return 0;
}