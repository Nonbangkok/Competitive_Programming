#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int dp[(int)1e6+10];
int main(){macos;

    int n;
    cin >> n;

    forr(i,1,n+1){
        dp[i]=1e9;
        int x=i;
        while(x){
            if(x%10!=0)dp[i]=min(dp[i],dp[i-(x%10)]+1);
            x/=10;
        }
    }
    cout << dp[n];

    return 0;
}