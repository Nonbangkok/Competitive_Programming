#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e5+10;
ll A[N],dp[N][N],n,c;

ll cal(ll a,ll b){
    return (a-b)*(a-b)+c;
}

ll jump(ll l,ll r){
    if(l>=r)return 0;
    if(dp[l][r])return dp[l][r];
    dp[l][r]=INT_MAX;
    forr(k,l+1,r)dp[l][r]=min(dp[l][r],cal(A[l],A[k])+jump(k,r));
    return dp[l][r];
}

int main(){macos;

    cin >> n >> c;
    forr(i,0,n)cin >> A[i];
    cout << jump(0,n-1);
    //wait for optimize

    return 0;
}