#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
ll n,ans=0;

void sSearch(ll i,ll J){
    if(i<=n){
        if(J==1)ans+=pow(2,n-i);
        else sSearch(i+1,1);
        sSearch(i+1,0);
    }
}

int main() {macos;

    cin >> n;
    sSearch(1,0);
    cout << ans;

    return 0;
}