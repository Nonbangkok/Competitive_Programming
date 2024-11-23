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

    ll n,sum = 0,i=2;
    cin >> n;
    while(n){
        sum += (n%10) * i;
        i++;
        n /= 10;
    }
    sum = 11 - (sum%11);
    if(sum==10)cout << 0;
    else if(sum==11)cout << 1;
    else cout << sum;

    return 0;
}