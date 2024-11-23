#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int n,A[11][11],mx=-1;
bool visited[11];

void ssearch(int i,int j,int sum){
    if(i==n)mx=max(mx,sum);
    else if(j+1<=n){
        // if(i-1>=1&&!visited[i-1]){
        //     visited[i-1]=true;
        //     ssearch(i-1,j+1,sum+A[i-1][j+1]);
        //     visited[i-1]=false;
        // }
        if(i+1<=n&&!visited[i+1]){
            visited[i+1]=true;
            ssearch(i+1,j+1,sum+A[i+1][j+1]);
            visited[i+1]=false;
        }
    }
}

int main(){macos;

    cin >> n;
    forr(i,1,n+1)forr(j,1,n+1)cin >> A[i][j];
    forr(i,1,n+1)ssearch(i,1,A[i][1]);
    cout << mx;

    return 0;
}