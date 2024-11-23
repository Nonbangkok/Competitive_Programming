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

vector<int> par(N),times(N);
int fp(int x){return (x==par[x]?par[x]:par[x]=fp(par[x]));}

int main(){macos;

    int n,m,q,u,v;
    cin >> n >> m >> q;

    forr(i,0,n)par[i]=i;
    forr(i,1,m+1){
        cin >> u >> v;u--;v--;
        if(fp(u)==fp(v))continue;
        times[u]=times[v]=i;
        par[par[v]]=par[u];
    }
    forr(i,1,q+1){
        cin >> u >> v;u--;v--;
        if(fp(u)!=fp(v))cout << -1 << endll;
        else cout << min(times[u],times[v]) << endll;
    }
    forr(i,0,n)cout << par[i] << sp;cout << endll;
    forr(i,0,n)cout << times[i] << sp;
    return 0;
}