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

    ll t,n;
    cin >> t;
    while(t--){
        cin >> n;
        ll l=0,r=LLONG_MAX,m;
        while(l<r){
            m=(l+r)>>1;
            ll sum=0,tmp=m,cnt=0;
            while(tmp){
                sum+=((tmp/10)+(tmp%10>=4));
                tmp/=10;
            }

            //cout << l << sp << m << sp << r << sp << sum << endll;
            if(m-sum<n)l=m+1;
            else r=m;
        }
        cout << l << endll;
    }

    return 0;
}