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
ll n,k,a[N],b[N],mn=LLONG_MAX;
void solve(ll i, ll salt,ll sweet,bool chk,ll p){
    if(i==n-1){
        if(!chk)return;
        mn = min(mn,abs(salt-sweet));
    }else{
        solve(i+1,salt,sweet,chk||false,p);
        solve(i+1,salt+a[i+1],sweet*b[i+1],chk||true,p);
        if(p<k)solve(i+1,salt+a[i+1]*-1,sweet*ll(ceil(double(b[i+1])/2.00)),chk||true,p+1);
    }
}

int main(){macos;

    cin >> n >> k;
    forr(i,0,n){
        ll x,y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
    }
    solve(-1,0,1,false,0);

    cout << mn;

    return 0;
}