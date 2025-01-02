#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6+10;
int n;
ll A[N];

ll solve(int l,int r){
    l+=5;r+=5;
    vector<ll> dp(r,0);
    forr(i,l,r)dp[i] = max(dp[i-1],dp[i-2]+A[i-5]);
    return dp[r-1];
}

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> A[i];

    if(n==1)cout << A[0];
    else cout << max(solve(0,n-1),solve(1,n));

    return 0;
}