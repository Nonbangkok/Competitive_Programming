#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
ll n,j,ans;
ll a[N];
map<ll,ll> mp;

int main(){macos;

    cin >> n;
    j = 1;
    forr(i,1,n+1){
        cin >> a[i];
        mp[a[i]]++;
        while(mp[a[i]]>1)mp[a[j++]]--;
        ans += i - j + 1;
    }
    cout << ans;

    return 0;
}