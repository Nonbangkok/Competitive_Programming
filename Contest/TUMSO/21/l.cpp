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

    ll t,n;
    cin >> t;

    while(t--){
        cin >> n;
        int r = n%3LL;
        if(n<3||n==4)cout << -1 << endll;
        else if(n==3)cout << 1 << endll;
        else if(r==1)cout << n/3-1 << endll;
        else cout << n/3 << endll;
    }

    return 0;
}