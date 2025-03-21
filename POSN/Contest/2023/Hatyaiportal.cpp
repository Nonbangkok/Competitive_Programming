#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e4 + 10;
bool vis[N];
ll dis[N];
ll n,u,ans;
pair<ll,ll> A[N];

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> A[i].first >> A[i].second;

    forr(i,1,n)dis[i] = 1e9;

    forr(i,0,n){
        u = -1;
        forr(j,0,n){
            if(vis[j])continue;
            if(u==-1||dis[u]>dis[j])u = j;
        }

        vis[u] = true;
        ans += dis[u];

        forr(j,0,n){
            if(vis[j])continue;
            dis[j] = min(dis[j],abs(A[u].first-A[j].first)+abs(A[u].second-A[j].second));
        }
    }

    cout << ans;

    return 0;
}