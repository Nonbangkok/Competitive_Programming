#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e6+10;
ll a[N];
int main(){macos;

    ll x,n,m,cnt=0;
    cin >> n >> m;
    forr(i,0,n){
        cin >> x;
        cnt+=a[x];
        a[m-x]++;
    }
    cout << cnt;

    return 0;
}