#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 15;
ll n,k,a[N],b[N],mn=LLONG_MAX,ans;

void solve(ll i, ll sweet,ll salt,bool chk){
    if(i==n-1){
        if(!chk)return;
        mn = min(mn,abs(sweet-salt));
    }else{
        solve(i+1,sweet,salt,chk);
        solve(i+1,sweet*a[i+1],salt+b[i+1],chk||true);
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n){
        ll x,y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
    }
    solve(-1,1,0,false);

    forr(i,1,mn+1)ans += (i*i*i-i*i+i);
    cout << ans;

    return 0;
}