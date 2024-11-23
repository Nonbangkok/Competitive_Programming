#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int t,a,b,c,sum=0;
    cin >> t;

    while(t--){
        cin >> a >> b >> c;
        cout << a*b-c << endll;
        sum+=a*b-c;
    }
    cout << sum;

    return 0;
 }
