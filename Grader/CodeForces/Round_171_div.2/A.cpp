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

    int t,x,y,k;
    cin >> t;

    while(t--){
        cin >> x >> y >> k;
        int z = min(x,y);
        cout << "0 0 " << z << sp << z << endll;
        cout << z << sp << 0 << sp << 0 << sp << z << endll;
    }

    return 0;
}