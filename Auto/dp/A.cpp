#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
int dp[N],A[N];
int main() {macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> A[i];
    dp[0]=0;
    forr(i,1,n){
        if(i==1)dp[i]=abs(A[i]-A[i-1]);
        else dp[i]=min(abs(A[i]-A[i-1])+dp[i-1],abs(A[i]-A[i-2])*3+dp[i-2]);
    }
    cout << dp[n-1];

    return 0;
}