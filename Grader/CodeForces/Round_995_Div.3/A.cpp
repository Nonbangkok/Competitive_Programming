#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 101;
int a[N],b[N];
int t,n;

int main(){macos;

    cin >> t;

    while(t--){
        cin >> n;
        forr(i,0,n)cin >> a[i];
        forr(i,0,n)cin >> b[i];

        int ans = 0;
        forr(i,0,n-1)if(a[i]>b[i+1])ans += a[i]-b[i+1];
        cout << ans+a[n-1] << endll;
    }

    return 0;
}