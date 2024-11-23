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

    int n;
    cin >> n;
    while(n--){
        ll a,b;
        cin >> a >> b;
        if(min(a,b)*2>=max(a,b)&&(a+b)%3==0)cout << "YES" << endll;
        else cout << "NO" << endll;
    }

    return 0;
}