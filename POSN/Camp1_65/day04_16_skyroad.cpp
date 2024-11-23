/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,mx=-999999,mn=999999;
    cin >> n;
    while(n!=0){
        mx=max(mx,n);
        mn=min(mn,n);
        cin >> n;
    }
    cout << mx-mn;

    return 0;
}
