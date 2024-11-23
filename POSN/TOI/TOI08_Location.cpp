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

    int m,n,k;
    cin >> m >> n >> k;
    int a[m+1][n+1];
    int qs[m+1][n+1];
    memset(qs,0,sizeof(qs));
    forr(i,1,m+1){
        forr(j,1,n+1){
            cin >> a[i][j];
            qs[i][j]=a[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }

    int mx=INT_MIN;
    forr(i,k,m+1){
        forr(j,k,n+1){
            mx=max(mx,qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k]);
        }
    }
    cout << mx;

	return 0;
}