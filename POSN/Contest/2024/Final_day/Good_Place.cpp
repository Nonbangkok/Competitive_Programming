#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
int x[N],y[N];
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n){
        cin >> x[i] >> y[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    cout << x[n/2] << sp << y[n/2];

    return 0;
}