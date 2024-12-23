#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6+10;
ll A[N];
ll m,n;

int main(){macos;

    cin >> m >> n;
    forr(i,0,m)cin >> A[i];

    ll l=0,r=1e12+10;
    while(l<r){
        ll mid  = (l+r)>>1;
        ll cnt = 0;
        forr(i,0,m)cnt += mid/A[i];
        if(cnt<n)l = mid+1;
        else r = mid;
    }
    cout << l;

    return 0;
}