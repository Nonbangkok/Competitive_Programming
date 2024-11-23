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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int a[n];
        forr(i,0,n)cin >> a[i];
        if(n==2&&abs(a[0]-a[1])!=1)cout << "YES" << endll;
        else cout << "NO" << endll;
    }

    return 0;
}