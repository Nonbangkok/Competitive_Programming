#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=101;
int dis[N][N];
int main(){macos;

    int n,e,a,b,c;
    cin >> n >> e;

    forr(i,0,n)forr(j,0,n)dis[i][j]=1e9;
    forr(i,0,e){
        cin >> a >> b >> c;
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
    }

    forr(k,0,n)forr(j,0,n)forr(i,0,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    ll sum=0;
    forr(i,0,n-1)sum+=dis[i][i+1];
    cout << sum;

    return 0;
}