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
ll n,k,x,mx;
ll qs[N];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> qs[i],qs[i] += qs[i-1];

    forr(i,1,n+1){
        mx = max(mx,min(qs[i],qs[n]-qs[i]));
    }
    cout << mx;

    return 0;
}