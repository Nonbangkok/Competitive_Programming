#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e4+10;
ll odd[N], even[N], dp[N];
int main(){macos;

    ll n,v,w;
    cin >> n >> v >> w;

    forr(i,1,n+1){
        ll temp;
        cin >> temp;
        odd[i]+=odd[i-1];
        even[i]+=even[i-1];
        if(temp&1)odd[i]+=temp;
        else even[i]+=temp;
    
    }

    forr(i,1,n+1)dp[i]=INT_MAX;
    dp[0] = 0;
    for(int r=2;r<=n;r+=2){ 
       for(int l=0;l<r;l+=2){
            int m = (l+r)>>1;
            
            if(odd[m]-odd[l]>v||even[r]-even[m]>w)continue;
            dp[r] = min(dp[r],dp[l]+1);
       }
    }
    cout << (dp[n]==INT_MAX?-1:dp[n]);

    return 0;
}