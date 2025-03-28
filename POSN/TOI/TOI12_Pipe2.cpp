#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 15010;
int n,k;
bool vis[N];
ll dis[N],w;
pair<ll,ll> pts[N];
vector<ll> ans;

int main(){macos;

    cin >> n >> k;
    forr(i,0,n)cin >> pts[i].first >> pts[i].second;

    forr(i,1,n)dis[i] = 1e18;

    forr(i,0,n){
        int u = -1;
        forr(j,0,n){
            if(vis[j])continue;
            if(u==-1||dis[u]>dis[j])u = j;
        }

        vis[u] = true;
        w += dis[u];
        ans.push_back(dis[u]);

        forr(j,0,n)if(!vis[j])dis[j] = min(dis[j],abs(pts[u].first-pts[j].first)+abs(pts[u].second-pts[j].second));
    }   

    sort(ans.rbegin(),ans.rend());
    forr(i,0,k-1)w -= ans[i];
    cout << w;

    return 0;
}