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

    ll k,n;
    cin >> k >> n;
    double sum[k],A[n];
    forr(i,0,n){
        cin >> A[i];
    }
    forr(i,0,k){
        sum[i]=0;
    }
    sort(A,A+n);
    forr(i,0,k){
        double temp=0;
        for(int j=i;j<n;j+=k){
            temp+=A[j];
            sum[i]+=temp;
        }
        cout << sum[i] << endll;
    }
    double ans=0;
    forr(i,0,k){
        ans += sum[i];
    }
    cout<<fixed<<setprecision(3)<<ans/n;

    return 0;
}