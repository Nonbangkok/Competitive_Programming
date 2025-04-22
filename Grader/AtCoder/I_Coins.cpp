#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 3010;
int n;
double p[N],dp[N],ans;

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> p[i];

    dp[0] = 1.0;
    forr(i,1,n+1)forl(j,i+1,-1){
        if(!j)dp[j] *= 1 - p[i];
        else dp[j] = (dp[j]*(1-p[i])) + (dp[j-1]*p[i]);
    }

    forr(i,n/2+1,n+1)ans += dp[i];
    coutf(10,ans);

    return 0;
}