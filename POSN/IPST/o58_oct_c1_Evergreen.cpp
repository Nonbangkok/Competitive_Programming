#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1010;
ll A[N];
int main(){macos;

    ll n,k;
    cin >> n >> k;
    forr(i,0,n)cin >> A[i];
    sort(A,A+n);
    
    ll l=0,r=1e9,m,all;
    while(l<r){
        m=(l+r)>>1;

        all=n*(m+1)*(m+1);
        forr(i,1,n){
            ll range=A[i]-A[i-1]-1;
            ll plant_grow=m-(range>>1);
            if(plant_grow<=0)continue;
            if(range&1)all-=plant_grow*plant_grow;
            else all-=plant_grow*(plant_grow+1);
        }
        if(all<k)l=m+1;
        else r=m;
    }
    cout << l;

    return 0;
}