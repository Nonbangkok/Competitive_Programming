#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,m;
int dp[1001][1001],table[1001][1001];

int main() {macos;

    int ans=-1;
    cin >> n >> m;
    forr(i,1,n+1){
        forr(j,1,m+1){
            cin >> table[i][j];
        }
    }

    forr(j,1,m+1){
        forr(i,1,n+1){
            dp[i][j]=max(dp[i][j-1],max(dp[i+1][j-1],dp[i-1][j-1]))+table[i][j];
            cout << dp[i][j] << sp;
            if(j==m){
                ans=max(ans,dp[i][j]);
            }
        }
        cout << endll;
    }
    cout << ans;
    

    return 0;
 }
