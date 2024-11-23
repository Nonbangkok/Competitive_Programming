#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int u,v,w;

    bool operator < (const Non &rhs) const{
        if(w!=rhs.w)return w>rhs.w;
        else return u<rhs.u;
    }
};

int find(vector<int> &par,int x){
    if(x!=par[x])par[x]=find(par,par[x]);
    return par[x];
}

int main() {macos;

    int n,e,a,b,c,cnt=0;
    ll ans=0;
    cin >> n >> e;
    vector<Non> edges;
    forr(i,0,e){
        cin >> a >> b >> c;
        edges.push_back({--a,--b,c});
    }
    sort(edges.begin(),edges.end());

    vector<int> par(n);
    forr(i,0,n)par[i]=i;
    for(auto [u,v,w]:edges){
        if(cnt==n-1)break;
        int pu=find(par,u),pv=find(par,v);
        if(pu!=pv){
            ans+=w;
            cnt++;
            par[pv]=par[pu];
        }
    }
    cout << ans-(n-1);

    return 0;
}