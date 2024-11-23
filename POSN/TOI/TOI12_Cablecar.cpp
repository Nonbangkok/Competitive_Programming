#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2510;
struct Non{
    int u,v,w;

    bool operator < (const Non &rhs)const{
        if(w!=rhs.w)return w>rhs.w;
        return u<rhs.u;
    }
};

vector<Non> edges;
vector<int> par(N);

int fp(int x){
    if(par[x]!=x)par[x]=fp(par[x]);
    return par[x];
}

int main(){macos;

    int n,m,a,b,c,src,des,p;
    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;a--;b--;
        edges.push_back({a,b,c-1});
    }
    sort(edges.begin(),edges.end());
    cin >> src >> des >> p;src--;des--;

    forr(i,0,n)par[i]=i;
    for(auto [u,v,w]:edges){
        if(fp(u)==fp(v))continue;
        par[par[v]]=par[u];
        if(fp(src)==fp(des)){
            cout << (p%w?p/w+1:p/w);
            return 0;
        }
    }

    return 0;
}