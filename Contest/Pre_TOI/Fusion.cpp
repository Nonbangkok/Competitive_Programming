#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e3 + 10;
ll n,k,a,b=1LL,ans;
ll arr[N];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> arr[i];
    a = arr[1];
    forr(i,2,n+1){
        b = a * arr[i];
        a += arr[i];
        ans += b;
    }
    cout << ans;

    return 0;
}