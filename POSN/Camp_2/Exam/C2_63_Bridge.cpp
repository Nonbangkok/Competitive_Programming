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
        if(w!=rhs.w)return w<rhs.w;
        return u<rhs.u;
    }
};

int find(vector<int> &par,int x){
    if(par[x]!=x) par[x]=find(par,par[x]);
    return par[x];
}

int main() {macos;

    ll n,e,a,b,c;
    cin >> n >> e;
    vector<Non> edges;
    forr(i,0,e){
        cin >> a >> b >> c;
        edges.push_back({--a,--b,c});
    }

    int cnt=0;
    ll dis=0;
    vector<int> par(n);
    forr(i,0,n)par[i]=i;
    sort(edges.begin(),edges.end());
    for(auto i : edges){
        if(cnt==n-1)break;
        int u=i.u,v=i.v;
        ll w=i.w;
        int pu=find(par,u),pv=find(par,v);
        if(pu!=pv){
            dis+=w;
            cnt++;
            par[pv]=par[pu];
        }
    }
    cout << dis << endll;

    vector<pair<ll,ll>> A;
    int k;
    ll cost=0,temp;
    cin >> k;
    forr(i,0,k){
        cin >> temp >> b;
        A.push_back({temp,b});
    }
    sort(A.begin(),A.end());
    for(auto i : A){
        if(dis>=i.second){
            dis-=i.second;
            cost+=i.first*i.second;
        }else{
            cost+=i.first*dis;
            break;
        }
    }
    cout << cost;

    return 0;
}