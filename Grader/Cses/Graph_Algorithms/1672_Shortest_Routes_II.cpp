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
ll dis[N][N],c;
int n,m,q,a,b;

int main() {macos;

    cin >> n >> m >> q;
    forr(i,0,n+1)forr(j,0,n+1)if(i!=j)dis[i][j]=ll(1e12);
    forr(i,0,m){
        cin >> a >> b >> c;
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
    }

    forr(k,1,n+1)forr(j,1,n+1)forr(i,1,n+1)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    
    forr(i,0,q){
        cin >> a >> b;
        if(dis[a][b]>=ll(1e12))cout << -1;
        else cout << dis[a][b];
        cout << endll;
    }

    return 0;
}