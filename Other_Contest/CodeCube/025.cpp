#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=602;
ll dp[N][N],qs[N];
int main(){macos;

    ll n;
    cin >> n;
    forr(i,1,n+1)cin >> qs[i],qs[i]+=qs[i-1];

    forr(sz,1,n)forr(l,0,n-sz){
        int r=l+sz;
        forr(k,l,r){
            ll rb=qs[r+1]-qs[k+1];
            ll lb=qs[k+1]-qs[l];
            dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]+min(lb,rb)*2+max(lb,rb));
        }
    }
    cout << dp[0][n-1];

    return 0;
}