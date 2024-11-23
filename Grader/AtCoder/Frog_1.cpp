#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+2;
ll A[N],dp[N];
int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n+1)cin >> A[i];

    forr(i,2,n+1){
        dp[i]=INT_MAX;
        if(i-1>=1)dp[i]=min(dp[i],dp[i-1]+abs(A[i]-A[i-1]));
        if(i-2>=1)dp[i]=min(dp[i],dp[i-2]+abs(A[i]-A[i-2]));
    }

    //forr(i,1,n+1)cout << A[i] << sp;
    //cout << endll;
    //forr(i,1,n+1)cout << dp[i] << sp;
    //cout << endll;

    cout << dp[n];

    return 0;
}