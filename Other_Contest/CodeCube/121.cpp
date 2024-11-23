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
        return w<rhs.w;
    }
};

int par[100001];
int findpar(int x){
    if(par[x]!=x)par[x]=findpar(par[x]);
    return par[x];
}

int main(){macos;

    int n,e;
    cin >> n;
    int A[n];
    forr(i,0,n)par[i]=i;
    forr(i,0,n)cin >> A[i];

    vector<Non> edges;
    cin >> e;
    forr(i,0,e){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edges.push_back({a,b,A[a]+A[b]});
    }
    sort(edges.begin(),edges.end());

    ll ans=0;
    for(auto [u,v,w]:edges){
        if(findpar(u)==findpar(v))continue;
        par[findpar(v)]=par[findpar(u)];
        ans+=w;
    }
    cout << ans;

    return 0;
}