#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10, M = 1e9 + 7;
ll n,m,k,a,b;
ll fac[N],inv[N],dp[3010];
vector<pair<ll,ll>> ob;

ll power(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)ans *= a,ans %= M;
        a *= a,a %= M;
        b >>= 1;
    }
    return ans;
}

ll cal(pair<ll,ll> p, pair<ll,ll> q){
    ll x = q.first - p.first;
    ll y = q.second - p.second;
    return fac[x+y] * inv[x] % M * inv[y] % M;
}

int main(){macos;

    fac[0] = inv[0] = 1LL;
    forr(i,1,N)fac[i] = (fac[i-1] * i) % M,inv[i] = power(fac[i],M-2);

    cin >> n >> m >> k;
    forr(i,0,k)cin >> a >> b,ob.push_back({a,b});
    ob.push_back({n,m});

    sort(ob.begin(),ob.end());

    forr(i,0,k+1){
        dp[i] = cal({1LL,1LL},ob[i]);
        forr(j,0,i){
            if(ob[i].first<ob[j].first||ob[i].second<ob[j].second)continue;
            dp[i] = (dp[i] - (dp[j] * cal(ob[j],ob[i])) % M + M) % M;
        }
    }

    cout << dp[k];

    return 0;
}