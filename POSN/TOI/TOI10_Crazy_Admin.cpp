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

    int k,n,mx=-1;
    cin >> k >> n;
    int A[n];
    forr(i,0,n){
        cin >> A[i];
        mx=max(mx,A[i]);
    }

    int l=mx,r=1e7,mid;
    while(l<=r){
        mid=(l+r)/2;
        int sum=0,cnt=0;
        forr(i,0,n){
            if(sum+A[i]<=mid){
                sum+=A[i];
            }else{
                sum=A[i];
                cnt++;
            }
        }
        if(cnt>=k) l=mid+1;
        else r=mid-1;
    }
    cout << r+1;

    return 0;
}