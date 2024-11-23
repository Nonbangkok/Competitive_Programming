#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll sumall(ll n){
    ll sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main() {macos;

    ll n,s;
    cin >> n >> s;

    ll l=0,r=n,mid,sum;
    while(l<=r){
        mid=(l+r)/2;
        sum=abs(mid-sumall(mid));
        if(l==r)break;
        if(sum<s)l=mid+1;
        else r=mid;
    }
    (sum>=s)?cout << n-mid+1 << endll << n:cout << 0 << endll << -1;

    return 0;
}