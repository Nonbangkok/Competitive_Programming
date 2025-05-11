#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5010;
int n;
ll a[N],dp[N],mx,mn;

int main(){macos;

    cin >> n;
    forr(i,1,n+1){
        cin >> a[i];
        mx = a[i],mn = a[i];
        forl(j,i,0){
            mx = max(mx,a[j]);
            mn = min(mn,a[j]);
            dp[i] = max(dp[i],dp[j-1]+mx-mn);
        }
    }

    cout << dp[n];

    return 0;
}