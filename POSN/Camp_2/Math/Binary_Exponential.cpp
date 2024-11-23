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

    int a,n;
    cin >> a >> n;

    int ans=1;
    while(n){
        if(n&1)ans*=a;
        a*=a;
        n>>=1;
    }
    cout << ans;

    return 0;
}