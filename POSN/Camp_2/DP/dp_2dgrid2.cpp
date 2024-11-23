#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int m,n,dp[100][100];
char table[100][100];

int main() {macos;

    cin  >> m >> n;
    forr(i,0,m){
        forr(j,0,n){
            cin >> table[i][j];
        }
    }
    
    forr(i,0,m){
        forr(j,0,n){
            if(i==0&&j==0)dp[i][j]=1;
            else if(table[i][j]=='#')dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout << dp[m-1][n-1];

    return 0;
 }