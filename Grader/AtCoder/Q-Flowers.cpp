#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
ll n,mx;
ll a[N],h[N],dp[N];

struct Fenwick{
    ll fw[2*N];

    Fenwick(){
        forr(i,0,2*N)fw[i] = 0;    
    }

    void update(ll idx,ll val){
        for(ll i=idx;i<N;i+=i&-i)fw[i] = max(fw[i],val);
    }

    ll query(ll idx){
        ll mx = 0;
        for(ll i=idx;i>0;i-=i&-i)mx = max(mx,fw[i]);
        return mx;
    }
}fw;

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> h[i];
    forr(i,1,n+1)cin >> a[i];

    // forr(i,1,n+1){
    //     forr(j,0,i){
    //         if(h[j]>h[i])continue;
    //         dp[i] = max(dp[i],dp[j]+a[i]);
    //         mx = max(mx,dp[i]);
    //     }
    // }

    forr(i,1,n+1){
        dp[i] = fw.query(h[i]) + a[i];
        fw.update(h[i],dp[i]);
        mx = max(mx,dp[i]);
    }
    cout << mx;

    return 0;
}