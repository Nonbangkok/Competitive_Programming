#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (ll i = a; i < n; i++)
#define forl(i, a, n) for (ll i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

static const ll MOD = 998244353;
static const ll N = 100000;

ll modExp(ll base, ll exp, ll m) {
    ll result = 1 % m;
    base %= m;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return result;
}

ll fact[N+1], invFact[N+1];
ll inv2[N+1];

void precompute() {
    fact[0] = 1;
    forr(i,1,N+1)fact[i] = (fact[i-1] * i) % MOD;

    invFact[N] = modExp(fact[N], MOD-2, MOD);
    for(ll i=N-1;i>=0;i--)invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    ll inv2_1 = modExp(2, MOD-2, MOD);
    inv2[0] = 1;
    forr(i,1,N+1)inv2[i] = (inv2[i-1] * inv2_1) % MOD;
}

ll nCr(ll n, ll r){
    if(r<0||r>n) return 0;
    return fact[n] * ((invFact[r] * invFact[n-r]) % MOD) % MOD;
}

int main(){macos;

    precompute();

    ll t; 
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        forr(i,1,n/2+1){
            ll ways = (nCr(n,i) - nCr(n,i-1) + MOD) % MOD;
            ll ans = (ways * inv2[n]) % MOD;
            cout << ans << sp;
        }
        cout << endll;
    }

    return 0;
}