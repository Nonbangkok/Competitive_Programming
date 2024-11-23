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
vector<ll> fval(N);
vector<ll> val(N);
vector<ll> par(N);
vector<ll> mx(N);

ll findpar(ll x){
    if(x!=par[x])par[x]=findpar(par[x]);
    val[x]=val[par[x]];
    return par[x];
}

ll findval(ll x,ll va){
    if(va!=val[par[x]])val[x]=findval(par[x],val[par[x]]);
    return val[par[x]];
}

int main(){macos;

    ll n,q,tmp,a,b;
    char ch;
    cin >> n >> q;
    forr(i,0,n)par[i]=mx[i]=i;

    forr(i,0,n){
        cin >> tmp;
        val[i]=fval[i]=tmp;
    }
    while(q--){
        cin >> ch;
        //cout << ch << endll;
        if(ch=='A'){
            cin >> a >> b;a--;b--;
            if(a>b)swap(a,b);
            if(findpar(a)==findpar(b))val[par[a]]+=fval[a]+fval[b];
            else if(findpar(b)>findpar(a)){
                mx[par[a]]=max(mx[par[a]],max(mx[par[a]],mx[par[b]]));
                val[par[a]]=val[a]+val[b];
                par[findpar(b)]=findpar(a);
            }else{
                mx[par[b]]=max(mx[par[b]],max(mx[par[a]],mx[par[b]]));
                val[par[b]]=val[a]+val[b];
                par[findpar(a)]=findpar(b);
            }
        }else if(ch=='B'){
            cin >> a;a--;
            findpar(a);
            cout << mx[par[a]]-par[a]+1 << endll;
        }else if(ch=='C'){
            cin >> a;a--;
            findpar(a);
            cout << findval(a,val[a]) << endll;
        }else if(ch=='D'){
            cin >> a;a--;
            findpar(a);
            cout << mx[par[a]]-par[a]+1 << sp;
            cout << findval(a,val[a]) << endll;
        }
        // forr(i,0,n)cout << val[i] << sp;cout << endll;
        // forr(i,0,n)cout << par[i] << sp;cout << endll;
        // forr(i,0,n)cout << mx[i] << sp;cout << endll;
        // cout << endll;
    }

    return 0;
}