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

    int n,x;
    cin >> n >> x;
    int a[n];
    forr(i,0,n)cin >> a[i];
    sort(a,a+n);
    forr(i,0,n)cout << a[i] << sp;
    cout << endll;
    cout << lower_bound(a,a+n,x)-a;

    return 0;
}