#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int A[100],dp[(int)1e6+10],n,m;

int coin(int i){
    if(i==0)return 0;
    if(i<0)return 1e9;
    if(dp[i])return dp[i];
    dp[i]=INT_MAX;
    forr(j,0,n)dp[i]=min(dp[i],coin(i-A[j])+1);
    return dp[i];
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)cin >> A[i];
    coin(m)>=1e9?cout << -1:cout << coin(m);

    return 0;
}