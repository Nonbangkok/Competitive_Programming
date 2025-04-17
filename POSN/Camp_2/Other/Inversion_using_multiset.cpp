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
int a[N];
int main(){macos;

    multiset <int> mp;
    int n,cnt=0;
    cin >> n;
    forr(i,0,n){
        cin >> a[i];
        mp.insert(a[i]);
        cnt += distance(mp.upper_bound(a[i]),mp.end());
    }
    cout << cnt << endll;

    return 0;
}