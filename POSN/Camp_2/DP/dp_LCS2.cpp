#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int dp[101][101];

int main() {macos;

    string s1,s2;
    int mx=-1,t,n1,n2;
    cin >> t;
    while(t--){
        cin >> n1 >> n2 >> s1 >> s2;
        forr(i,1,n1+1){
            forr(j,1,n2+1){
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else if(s1[i-1]!=s2[j-1])dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[n1][n2];
        memset(dp,0,sizeof(dp));
    }

    return 0;
 }
