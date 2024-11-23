#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e6+2;
int A[N],dp[N];
int main() {macos;

    int n;
    cin >> n;
    forr(i,1,n+1)cin >> A[i];
    forr(i,1,n+1){
        if(i==1)dp[i]=A[i];
        else dp[i]=max(dp[i-1],dp[i-2]+A[i]);
    }
    cout << dp[n];

    return 0;
}