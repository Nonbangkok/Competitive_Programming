#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
int A[N],dp[N];
int main(){macos;

    int n;cin >> n;
    forr(i,1,n+1){
        cin >> A[i];
        if(!A[i])dp[i]=dp[i-1];
        else if(A[i-1]==1||A[i]==3||A[i-1]==2||A[i]==2)dp[i]=max(dp[i-2]+1,dp[i-1]);
        else dp[i]=dp[i-1]+1;
    }
    cout << dp[n];

    return 0;
}