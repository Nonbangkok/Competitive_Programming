#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=502;
int qs[N][N];
int main() {macos;

    int n,m,tree,x,y;
    forr(t,0,2){
        cin >> n >> m >> tree;
        forr(i,0,tree){
            cin >> x >> y;
            qs[++x][++y]=1;
        }
        forr(i,1,n+1)forr(j,1,m+1)qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        int ans=INT_MIN;
        forr(i,1,n+1){
            forr(j,1,m+1){
                int size=min(n-i+1,m-j+1);
                forr(k,1,size+1){
                    int big=qs[i+k-1][j+k-1]-qs[i-1][j+k-1]-qs[i+k-1][j-1]+qs[i-1][j-1];
                    int small=qs[i+k-2][j+k-2]-qs[i][j+k-2]-qs[i+k-2][j]+qs[i][j];
                    if(big==small)ans=max(ans,k);
                }
            }
        }
        cout << ans << endll;
        forr(i,0,n+1)forr(j,0,m+1)qs[i][j]=0;
    }

    return 0;
}
