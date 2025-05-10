#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e4 + 10;
ll n,v,w,x;
ll even[N],odd[N],dp[N];

int main(){macos;

    cin >> n >> v >> w;
    forr(i,1,n+1){
        cin >> x;
        odd[i] = odd[i-1] + (x&1?x:0);
        even[i] = even[i-1] + (x&1?0:x);
    }

    for(int r=2;r<=n;r+=2){
        dp[r] = 1e18;
        for(int l=0;l<r;l+=2){
            int m = (l+r) >> 1;
            if(odd[m]-odd[l]>v||even[r]-even[m]>w)continue;
            dp[r] = min(dp[r],dp[l]+1);
        }
    }

    cout << (dp[n]!=1e18?dp[n]:-1);

    return 0;
}