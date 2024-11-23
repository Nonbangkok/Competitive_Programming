#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10,M=101;
int dp[N],W[M],V[M],sum=0,ans=-1;
int main(){macos;

    int n,w;
    cin >> n >> w;
    forr(i,0,n){
        cin >> W[i] >> V[i];
        sum+=V[i];
    }

    forr(i,0,sum+1)dp[i]=1e9;
    dp[0]=0;
    forr(i,0,n){
        forl(j,sum-V[i],-1){
            dp[j+V[i]]=min(dp[j+V[i]],dp[j]+W[i]);
            if(dp[j+V[i]]<=w)ans=max(ans,j+V[i]);
        }
    }
    cout << ans;

    return 0;
}