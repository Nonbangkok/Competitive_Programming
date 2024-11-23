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

    ll n;
    cin >> n;
    cout << n << sp;
    while(n!=1){
        if(n&1)n=n*3+1;
        else n>>=1;
        cout << n << sp;
    }

    return 0;
}