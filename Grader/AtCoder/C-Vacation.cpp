#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
int dp[N][3];
int main(){macos;

    int n,mx=-1;
    cin >> n;
    forr(i,1,n+1)forr(j,0,3){
        cin >> dp[i][j];
        dp[i][j]+=max(j!=0?dp[i-1][0]:0,max(j!=1?dp[i-1][1]:0,j!=2?dp[i-1][2]:0));
        if(i==n)mx=max(mx,dp[i][j]);
    }
    cout << mx;

    return 0;
}