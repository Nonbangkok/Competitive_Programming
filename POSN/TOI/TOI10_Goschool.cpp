#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=51;
bool A[N][N];
ll dp[N][N];
int main(){macos;

    int m,n,k,a,b;
    cin >> m >> n >> k;
    forr(i,0,k)cin >> a >> b,A[a][b]=true;

    dp[1][1]=1;
    forr(i,1,m+1){
        forr(j,1,n+1){
            if(A[i][j])continue;
            dp[i][j]+=dp[i][j-1]+dp[i-1][j];
        }
    }

    cout << dp[m][n];

    return 0;
}