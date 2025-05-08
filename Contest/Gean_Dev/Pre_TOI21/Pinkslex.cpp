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
ll n,k,mn=1e18;
ll a[N];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> a[i],mn = min(mn,a[i]);

    if(n==k)cout << mn;

    return 0;
}