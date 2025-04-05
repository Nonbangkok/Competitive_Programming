#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = (1<<20);
ll n,q,k,a,b;
ll dp[N],w[N];
string s;

int main(){macos;

    cin >> n >> q;
    forr(i,0,1<<n){
        cin >> s >> b;
        a = 0;
        forr(i,0,n)a = (a<<1) + (s[i]-'0');
        w[a] = b;
    }

    forr(i,1,1<<n){
        dp[i] = -1e18;
        forr(j,0,n){
            if(!(i&(1<<j)))continue;
            dp[i] = max(dp[i],dp[i^(1<<j)] + w[i]);

            k = j + 1;
            if(k==n||!(i&(1<<k)))continue;
            dp[i] = max(dp[i],dp[(i^(1<<j))^(1<<k)] + w[i]);
        }
    }

    while(q--){
        cin >> s;
        a = 0;
        forr(i,0,n)a = (a<<1) + (s[i]-'0');
        cout << dp[a] << endll;
    }

    return 0;
}