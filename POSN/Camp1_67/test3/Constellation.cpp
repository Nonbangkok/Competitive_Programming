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

    string a,b;
    cin >> a >> b;
    ll suma = 0,sumb=0;
    forr(i,0,a.size()){
        suma = (suma * 4) + (a[i] - '0');
    }
    forr(i,0,b.size()){
        sumb = (sumb * 4) + (b[i] - '0');
    }
    cout << suma%sumb;

    return 0;
}