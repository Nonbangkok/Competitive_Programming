#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll sum = 0;
        for(ll i=1;i*i<=n;i++){
            if(n%i)continue;
            if(i==n/i)sum += i;
            else sum += i + n/i;
        }
        // for(ll i=2;i<=n/2;i++){
        //     if(n%i)continue;
        //     if(i==n/i)sum += i;
        //     else sum += i + n/i;
        // }
        // for(int i=2;i<n;i++){
        //     if(n%i)continue;
        //     sum += i;
        // }
        cout << (n==sum-n?"Perfect":"Not Perfect") << endll;
    }

    return 0;
}