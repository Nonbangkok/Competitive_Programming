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
    int a,b;
    ll c;
};

const int N = 2510;
int n,m,a,b;
ll dis[N],c;
bool chk = false;
vector<Non> edges;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    forr(i,1,n+1)dis[i]=-1e18;
    dis[1] = 0;
    forr(k,0,n-1){
        for(auto [u,v,w]:edges){
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
            }
        }
    }

    for(auto [u,v,w]:edges){
        if(dis[v]<dis[u]+w){
            chk = true;
            break;
        }
    }

    cout << (chk?-1:dis[n]);

    return 0;
}
 