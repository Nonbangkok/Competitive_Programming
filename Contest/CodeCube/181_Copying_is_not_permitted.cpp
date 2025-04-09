#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 4e4 + 10;
int n,m,q,a,b,c;
int p[N];
vector<tuple<int,int,int>> edges;
vector<pair<int,int>> query;

int fp(int x){
    if(p[x] != x)p[x] = fp(p[x]);
    return p[x];
}

int solve(int mid){
    forr(i,1,n+1)p[i] = i;
    for(auto [u,v,w]:edges){
        if(w >= mid || fp(u) == fp(v))continue;
        p[fp(v)] = fp(u);
    }
    for(auto [u,v]:query)if(fp(u)==fp(v))return 0;
    return 1;
}

int main(){macos;

    cin >> n >> m >> q;
    forr(i,0,m){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    forr(i,0,q){
        cin >> a >> b;
        query.push_back({a,b});
    }

    int l = 0, r = 1e9, mid;
    while(l<r){
        mid = (l+r) >> 1;
        if(solve(mid))l = mid + 1;
        else r = mid;
    }

    cout << (l!=1e9?l-1:-1);

    return 0;
}