#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5+10;
int dp[N],v[110];
int m,n;

int main(){macos;

    cin >> m >> n;
    forr(i,0,n)cin >> v[i];
    forr(i,1,m+1)dp[i] = 1e9;
    forr(i,1,m+1)forr(j,0,n)if(i-v[j]>=0)dp[i] = min(dp[i],dp[i-v[j]]+1);
    cout << (dp[m]!=1e9?dp[m]:-1);

    return 0;
}