#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=3000+10;
double A[N],dp[N];
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> A[i];

    dp[0]=1.0;
    forr(i,0,n){
        for(int j=i+1;j>=0;j--) {
            if(!j)dp[j]=dp[j]*(1-A[i]);
            else dp[j]=dp[j-1]*A[i]+dp[j]*(1-A[i]);
        }
            forr(i,0,n+1)cout << dp[i] << sp;cout << endll;
    }


    // double ans=0.0;
    // forr(i,0,n+1)if(i>n-i)ans+=dp[i];
    // cout << fixed << setprecision(10) << ans;

    return 0;
}