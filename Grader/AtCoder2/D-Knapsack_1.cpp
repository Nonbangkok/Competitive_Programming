#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 110, M = 1e5 + 10;
ll n,w;
ll dp[M],W[N],V[N];

int main(){macos;

    cin >> n >> w;
    forr(i,1,n+1)cin >> W[i] >> V[i];

    // forr(i,1,n+1){
    //     forl(j,w,-1){
    //         if(j-W[i]>=0)dp[j] = max(dp[j],dp[j-W[i]]+V[i]);
    //     }
    // }

    forr(i,1,n+1){
        forl(j,w,W[i]-1){
            dp[j] = max(dp[j],dp[j-W[i]]+V[i]);
        }
    }

    cout << dp[w];

    return 0;
}