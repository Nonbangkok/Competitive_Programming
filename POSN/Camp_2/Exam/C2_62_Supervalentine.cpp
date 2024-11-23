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
    ll u,v,w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w) return w>rhs.w;
        else return u<rhs.u;
    }
};

int find(vector<int> &par,int x){
    if(par[x]!=x)par[x]=find(par,par[x]);
    return par[x];
}

int main() {macos;

    ll a,b,c,n,e;
    cin >> n >> e;
    vector<Non> edges;
    forr(i,0,e){
        cin >> a >> b >> c;
        edges.push_back({--a,--b,c});
    }
    sort(edges.begin(),edges.end());
    vector<int> par(n);
    forr(i,0,n) par[i]=i;
    ll cnt=0,ans=0;
    for(auto i : edges){
        if(cnt==n-1)break;
        ll u=i.u,v=i.v,w=i.w;
        int pu=find(par,u),pv=find(par,v);
        if(pu!=pv){
            cnt++;
            ans+=w;
            par[pv]=par[pu];
        }
    }
    cout << ans-cnt;

    return 0;
}