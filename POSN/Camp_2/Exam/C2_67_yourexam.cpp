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
ll dp[N],A[N],qs[N];
ll n,m,q,x;


int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1)cin >> A[i];
    
    forr(i,1,n+2)dp[i] = max(dp[i-1]+A[i-1],A[i-1]);
    forr(i,1,n+2)dp[i] = max(dp[i],dp[i-1]);
    forr(i,1,n+2)qs[i] = qs[i-1] + dp[i];

    cin >> q;
    while(q--){
        cin >> x;
        cout << qs[x]-qs[max(0LL,x-m)] << endll;
    }

    return 0;
}