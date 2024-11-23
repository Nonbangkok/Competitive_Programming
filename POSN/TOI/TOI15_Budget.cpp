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
    int u,v,w;

    bool operator <(const Non &rhs)const{
        if(w!=rhs.w)return w<rhs.w;
        return v>rhs.v;
    }
};

int par[3001];
int findpar(int x){
    if(par[x]!=x)par[x]=findpar(par[x]);
    return par[x];
}

int main(){macos;

    int n,e,a,b,c,d,k;
    cin >> n >> e;
    forr(i,0,n)par[i]=i;
    vector<Non> edges;
    forr(i,0,e){
        cin >> a >> b >> c >> d;
        if(!d)edges.push_back({a,b,c});
        else par[findpar(b)]=par[findpar(a)];
    }
    sort(edges.begin(),edges.end());
    
    cin >> k;
    vector<pair<int,int>> package;
    forr(i,0,k){
        cin >> a >> b;
        package.push_back({a,b});
    }
    sort(package.begin(),package.end());
    
    int ans=0;
    forr(i,0,e){
        auto [u,v,w]=edges[i];
        if(findpar(u)==findpar(v))continue;
        int mn=1e9;
        for(auto p :package)if(p.first>=w)mn=min(mn,p.second);
        ans+=mn;
        par[findpar(u)]=par[findpar(v)];
    }
    cout << ans;

    return 0;
}