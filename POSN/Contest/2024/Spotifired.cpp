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

    ll q;
    cin >> q;

    while(q--){
        ll n;
        cin >> n;
        unsigned long long l=0,r=n,mid;
        while(l<r){
            mid=(l+r)/2;
            ll sum=0,tmp=mid;
            while(tmp){
                sum+=tmp/10;
                tmp/=10;
            }
            if(mid+sum<n)l=mid+1;
            else r=mid;
        }
        cout << l << sp;
    }

    return 0;
}