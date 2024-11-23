#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,m,k;
    cin >> n >> m >> k;
    int A[n+2][m+2],qs[n+2][m+2],qs2[n+2][m+2],tri[n+2][m+2],tri2[n+2][m+2];
    memset(qs,0,sizeof(qs));
    memset(qs2,0,sizeof(qs2));
    memset(tri,0,sizeof(tri));
    memset(tri2,0,sizeof(tri2));

    forr(i,1,n+1)forr(j,1,m+1)cin >> A[i][j];
    forr(i,1,n+1)forr(j,1,m+1){
        qs[i][j]=A[i][j]+qs[i][j-1]+qs[i-1][j]-qs[i-1][j-1];
        tri[i][j]=tri[i-1][j-1]+qs[i][j]-qs[i-1][j];
    }
    forr(i,1,n+1)forl(j,m,0){
        qs2[i][j]=A[i][j]+qs2[i-1][j]+qs2[i][j+1]-qs2[i-1][j+1];
        tri2[i][j]=tri2[i-1][j+1]+qs2[i][j]-qs2[i-1][j];
    }
    int ans=INT_MIN;
    forr(i,k,n+1)forr(j,k,m+1)ans=max(ans,tri[i][j]-tri[i-k][j-k]-(qs[i][j-k]-qs[i-k][j-k]));
    forr(i,k,n+1)forl(j,m-k+1,0)ans=max(ans,tri2[i][j]-tri2[i-k][j+k]-(qs2[i][j+k]-qs2[i-k][j+k]));
    cout << ans;

    return 0;
}