#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=22,M=1e9+7;
bool A[N][N];
ll dp[N][1<<N];
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n)forr(j,0,n)cin >> A[i][j];
    forr(i,0,n)forr(k,0,1<<n){
        if(i&&!dp[i-1][k])continue;
        forr(j,0,n){
            if(k&(1<<j)||!A[i][j])continue;
            dp[i][k|(1<<j)]+=(i-1>=0?dp[i-1][k]:1),dp[i][k|(1<<j)]%=M;
        }
    }
    cout << dp[n-1][(1<<n)-1];

    return 0;
}