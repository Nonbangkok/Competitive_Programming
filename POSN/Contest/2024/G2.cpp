#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int par[1001];
int findpar(int x){
    if(par[x]!=x)par[x]=findpar(par[x]);
    return par[x];
}

int main(){macos;

    int n,m,q,a,b;
    cin >> n >> m;
    forr(i,0,n+1)par[i]=i;
    forr(i,0,m){
        cin >> a >> b;
        par[findpar(a)]=par[findpar(b)];
    }

    cin >> q;
    forr(i,0,q){
        cin >> a >> b;
        (findpar(a)==findpar(b))?cout << "YES":cout << "NO";
        cout << endll;
    }

    return 0;
}