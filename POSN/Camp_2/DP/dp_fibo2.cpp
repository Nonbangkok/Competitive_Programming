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

   int n;
   cin >> n;
   int dp[n];
   forr(i,0,n){
         if(i==0||i==1){
            dp[i]=1;
         }else{
            dp[i]=dp[i-1]+dp[i-2];
         }
    }
   cout << dp[n-1] << sp;  

   return 0;
 }