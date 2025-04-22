#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 51, M = 1e9 + 7;

struct Non{
    int n,m;
    ll a[N][N];

    Non(int x, int y,ll z){
        n = x,m = y;
        forr(i,0,n)forr(j,0,m)a[i][j] = z;
    }

    Non operator * (const Non &b){
        Non c(n,b.m,0);
        forr(i,0,n)forr(j,0,b.m)forr(k,0,m)c.a[i][j] += a[i][k] * b.a[k][j],c.a[i][j] %= M;
        return c;
    }

    Non& operator *= (const Non &b){
        *this = *this * b;
        return *this;
    }
};

int n;
ll k,p,ans;

int main(){macos;

    cin >> n >> k;
    Non a(n,n,0),dp(n,1,1);
    forr(i,0,n)forr(j,0,n)cin >> a.a[i][j];

    p = k;
    while(p){
        if(p&1)dp = a * dp;
        a *= a;
        p >>= 1;
    }
    forr(i,0,n)ans += dp.a[i][0],ans %= M;
    cout << ans;

    return 0;
}