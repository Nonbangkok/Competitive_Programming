#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e6+100;
ll dp[N];
int main() {macos;

    int n;
    cin >> n;
    dp[1]=500;
    dp[2]=800;
    dp[5]=1500;
    dp[15]=3000;
    forr(i,1,n+15){
        if(!dp[i])dp[i]=1e9;
        if(i-1>=1)dp[i]=min(dp[i],dp[i-1]+500);
        if(i-2>=1)dp[i]=min(dp[i],dp[i-2]+800);
        if(i-5>=1)dp[i]=min(dp[i],dp[i-5]+1500);
        if(i-15>=1)dp[i]=min(dp[i],dp[i-15]+3000);
    }
    forr(i,n,n+15){
        dp[n]=min(dp[n],dp[i]);
    }
    cout << dp[n];

    return 0;
}