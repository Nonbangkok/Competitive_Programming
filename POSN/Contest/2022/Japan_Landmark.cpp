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
int val[N],dp[N];
int main(){macos;

    int n,q,k;
    cin >> n;
    forr(i,0,n){
        cin >> val[i];
        dp[i]=max(dp[i-1],dp[i-2]+val[i]);
    }

    cin >> q;
    while(q--){
        cin >> k;
        int idx=lower_bound(dp,dp+n,k)-dp;
        (idx==n)?cout << 0:cout << idx+1;
        cout << endll;
    }

    return 0;
}