#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (ll i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int M=1e6+10,MOD=1e9+7;
ll fac[M],A[M];
int main(){macos;

    fac[1]=1;
    forr(i,2,M)fac[i]=(fac[i-1]*i)%MOD;

    int n,x;
    cin >> n;

    forr(i,0,2*n-1){
        cin >> x;
        A[x]++;
    }
    
    ll ans=1;
    forr(i,1,n+1){
        A[i]--;
        if(A[i]>1)ans=(ans*fac[A[i]])%MOD;
    }
    cout << ans;

    return 0;
}