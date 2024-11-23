#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e5+10;
vector<ll> val(N),fval(N),par(N);
vector<pair<ll,ll>> dis(N); 

ll findpar(ll x){
    return x==par[x]?x:par[x]=findpar(par[x]);
}

int main(){macos;

    ll n,q,tmp,a,b;
    char ch;
    cin >> n >> q;
    forr(i,1,n+1)cin >> tmp,val[i]=fval[i]=tmp,par[i]=i,dis[i]={i,i};
    while(q--){
        cin >> ch;
        if(ch=='A'){
            cin >> a >> b;
            if(findpar(a)==findpar(b))val[par[b]]+=fval[a]+fval[b];
            else{
                val[par[b]]+=val[par[a]];
                dis[par[b]].first=min(dis[par[b]].first,dis[par[a]].first);
                dis[par[b]].second=max(dis[par[b]].second,dis[par[a]].second);
                par[findpar(a)]=par[b];
            }
        }else if(ch=='B'){
            cin >> a;
            cout << dis[findpar(a)].second-dis[par[a]].first+1 << endll;
        }else if(ch=='C'){
            cin >> a;
            cout << val[findpar(a)] << endll;
        }else if(ch=='D'){
            cin >> a;
            cout << dis[findpar(a)].second-dis[par[a]].first+1 << sp << val[par[a]] << endll;
        }
        // forr(i,1,n+1)cout << par[i] << sp;cout << endll;
        // forr(i,1,n+1)cout << val[i] << sp;cout << endll;
        // forr(i,1,n+1)cout << fval[i] << sp;cout << endll;
        // forr(i,1,n+1)cout << dis[i].first << sp;cout << endll;
        // forr(i,1,n+1)cout << dis[i].second << sp;cout << endll;
    }

    return 0;
}