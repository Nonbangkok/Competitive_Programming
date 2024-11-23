#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    ll t;
    cin >> t;
    while(t--){
        ll a,b,c,k,l=0,r=1e7,mid;
        cin >> a >> b >> c >> k;
        int chk=1;
        while(l<=r){
            mid=(l+r)/2;
            ll sum=a*mid*mid+b*mid+c;
            if(sum>=k)r=mid-1;
            else l=mid+1;
            //cout << l << sp << mid << sp << r << endll;
        }
        cout << l << endll;
    }


    return 0;
}