#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,mn=1000001;
    ll m;
    cin >> n >> m;
    int A[n];
    forr(i,0,n){
        cin >> A[i];
        mn=min(mn,A[i]);
    }
    ll l=0,r=mn*m,mid;

    while(l<=r){
        mid=(l+r)/2;
        ll sum=0;
        forr(i,0,n)sum+=mid/A[i];
        if(sum>=m) r=mid-1;
        else if(sum<m) l=mid+1;
    }
    cout << r+1;

    return 0;
}