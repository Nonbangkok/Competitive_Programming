#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int n,k;
int a[N],dp[N];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> a[i];

    forr(i,2,n+1){
        dp[i] = 1e9;
        forr(j,1,k+1){
            if(i-j<1)break;
            dp[i] = min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
        }
    }

    cout << dp[n];

    return 0;
}