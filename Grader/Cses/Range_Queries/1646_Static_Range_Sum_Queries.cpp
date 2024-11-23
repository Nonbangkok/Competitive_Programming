#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    ll n,q;
    cin >> n >> q;
    ll qs[n+1];qs[0]=0;
    forr(i,1,n+1){
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }
    ll a,b;
    while(q--){
        cin >> a >> b;
        cout << qs[b]-qs[a-1] << endll;
    }

    return 0;
}