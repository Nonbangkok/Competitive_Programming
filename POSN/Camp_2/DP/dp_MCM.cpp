#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int A[102],dp[102][102];

int MCM(int l,int r){
    if(l>=r)return 0;
    if(dp[l][r])return dp[l][r];
    dp[l][r]=1e9;
    forr(k,l,r)dp[l][r]=min(dp[l][r],MCM(l,k)+MCM(k+1,r)+(A[l-1]*A[k]*A[r]));
    return dp[l][r];
}

int main() {macos;

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        forr(i,0,n){
            cin >> A[i];
        }
        cout << MCM(1,n-1) << endll;
        memset(dp,0,sizeof(dp));
    }

    return 0;
 }