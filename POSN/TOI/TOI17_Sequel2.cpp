#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10, M = 410;
ll n,q,k,l,r,m,sum;
ll a[N],dp[M][N];

int main(){macos;

    cin >> n >> q;
    k = ceil(sqrt(n));
    forr(i,1,n+1)cin >> a[i];
    forr(j,1,n+1)forr(i,1,k+1)
        dp[i][j] = dp[i][max(0,j-i)] + a[j];

    while(q--){
        cin >> l >> m >> r;
        if(m<=k){
            r = l + (r-l)/m * m;
            cout << dp[m][r] - dp[m][max(0LL,l-m)] << sp;
        }else{
            sum = 0;
            for(int i=l;i<=r;i+=m)sum += a[i];
            cout << sum << sp;
        }
    }

    return 0;
}