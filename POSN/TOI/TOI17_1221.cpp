#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 510;
int n,m,q,a,b;
ll dis[N][N],cnt[N][N],c;
ll w[N];

int main(){macos;

    cin >> n >> m >> q;
    forr(i,1,n+1)forr(j,1,n+1)dis[i][j] = 1e18,cnt[i][j] = 2;
    forr(i,1,n+1)cin >> w[i];
    forr(i,1,n+1)forr(j,1,n+1)dis[i][j] = w[i] + w[j];
    forr(i,0,m){
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = c;
    }

    forr(k,1,n+1)forr(i,1,n+1)forr(j,1,n+1){
        if(dis[i][j]>dis[i][k]+dis[k][j]){
            dis[i][j] = dis[i][k] + dis[k][j];
            cnt[i][j] = cnt[i][k] + cnt[k][j];
        }else if(dis[i][j]==dis[i][k]+dis[k][j])cnt[i][j] = max(cnt[i][j],cnt[i][k] + cnt[k][j]);
    }

    while(q--){
        cin >> a >> b;
        cout << dis[a][b] << sp << cnt[a][b] << endll;
    }

    return 0;
}