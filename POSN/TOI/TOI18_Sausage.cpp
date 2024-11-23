#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=5000;
ll n,A[N],dp[N][N],par[N];

ll maxone(ll l,ll r){
    if(l>r)return 0;
    if(dp[l][r])return dp[l][r];
    return dp[l][r]=max(maxone(l+1,r)+A[l],maxone(l,r-1)+A[r])+abs(A[l]-A[r]);
}

ll patition(ll l){
    if(l==n)return 0;
    if(par[l])return par[l];
    forr(r,l,n)par[l]=max(par[l],maxone(l,r)+patition(r+1));
    return par[l];
}

int main() {macos;

    cin >> n;
    forr(i,0,n)cin >> A[i];
    cout << patition(0);

    return 0;
}