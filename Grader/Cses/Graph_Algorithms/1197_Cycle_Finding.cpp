#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2510;
int n,m,a,b,st;
int p[N];
ll dis[N],c;
vector<tuple<int,int,ll>> edges;
vector<int> ans;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    forr(i,2,n+1)dis[i] = 1e18;
    forr(i,0,n){
        st = 0;
        for(auto [u,v,w]:edges){
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                p[v] = u;
                st = v;
            }
        }
    }

    if(!st){cout << "NO";return 0;}

    forr(i,0,n)st = p[st];
    int cur = st;
    while(1){
        ans.push_back(cur);
        if(cur==st&&ans.size()>1)break;
        cur = p[cur];
    }
    reverse(ans.begin(),ans.end());

    cout << "YES" << endll;
    for(int v:ans)cout << v << sp;

    return 0;
}