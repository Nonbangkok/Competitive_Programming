#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e6+10;
int dp[N];
int main() {macos;

    int n;
    cin >> n;
    dp[0]=(int)1e9;
    dp[1]=0;
    forr(i,2,n+1){
        dp[i]=(int)1e9;
        if(!(i%2))dp[i]=min(dp[i],dp[i/2]+1);
        if(!(i%3))dp[i]=min(dp[i],dp[i/3]+1);
        dp[i]=min(dp[i],dp[i-1]+1);
    }
    cout << dp[n];

    return 0;
}