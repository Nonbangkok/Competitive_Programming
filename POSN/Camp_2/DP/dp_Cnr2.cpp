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

    int n,r,dp[1000][1000];
    cin >> n >> r;
    forr(i,0,n+1){
        forr(j,0,i+1){
            if(j==0||i==j)dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    /*
     forr(i,0,10){
        forr(j,0,10){
            cout << dp[i][j];
        }
        cout << endll;
    } */
    cout << dp[n][r];

    return 0;
 }
