#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int find(int par[],int i){
    if(par[i]!=i)par[i]=find(par,par[i]);
    return par[i];
}

int main() {macos;

    int n,m,q;
    cin >> n >> m;
    int par[n];
    forr(i,0,n)par[i]=i;
    //for(auto j : par)cout << j << sp;
    //cout << endll;
    forr(i,0,m){
        int r,s;
        cin >> r >> s;
        r-=1,s-=1;
        int pr=find(par,r);
        int ps=find(par,s);
        //par[pr]=par[ps];
        //par[ps]=par[pr];
        par[max(pr,ps)]=par[min(pr,ps)];
        //for(auto j : par)cout << j << sp;
        //cout << endll;
    }
    cin >> q;
    forr(i,0,q){
        int a,b;
        cin >> a >> b;
        a-=1,b-=1;
        if(find(par,a)==find(par,b))cout << "YES" << endll;
        else cout << "NO" << endll;
    }

    return 0;
}