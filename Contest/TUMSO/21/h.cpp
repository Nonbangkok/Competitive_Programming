#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

static int N = 30; 
static ll dp[30][200001];

int main(){macos;

    ll n,q;
    cin >> n >> q;

    vector<ll> a(n+1);
    forr(i,1,n+1)cin >> a[i];

    forr(b,0,N){
        dp[b][0] = 0;
        forr(i,1,n+1){
            dp[b][i] = dp[b][i-1];
            if((a[i]>>b)&1)dp[b][i]++;
        }
    }

    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        ll ans = 0,len = r - l + 1; 
        forr(b,0,N){
            ll cnt = dp[b][r]-dp[b][l-1];
            if(((x>>b)&1)==1){
                ll oneCount = len - cnt;
                ans += (oneCount << b);
            }else ans += (cnt << b);
        }

        cout << ans << endll;
    }


    return 0;
}