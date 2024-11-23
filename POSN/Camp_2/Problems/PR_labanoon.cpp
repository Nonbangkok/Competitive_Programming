#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

  int n,k;
  cin >> n;
  int A[n+1];
  forr(i,1,n+1)cin >> A[i];
  cin >> k;
  int dp[k+1];
  dp[0]=0,dp[1]=A[1];

  forr(i,2,k+1){
    dp[i]=-1;
      forr(j,1,n+1){
        if(i>=j)dp[i]=max(dp[i],dp[i-j]+A[j]);
      }
  }
  //forr(i,1,k+1)cout << dp[i] << sp;
  cout << dp[k];
  
  return 0;
}