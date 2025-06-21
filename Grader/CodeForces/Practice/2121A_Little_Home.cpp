#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 11;
int t,n,s;
int a[N];

void solve(){
    cin >> n >> s;
    forr(i,0,n)cin >> a[i];
    cout << min(abs(s-a[0]),abs(s-a[n-1])) + abs(a[0]-a[n-1]) << endll;
}

int main(){macos;

    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}