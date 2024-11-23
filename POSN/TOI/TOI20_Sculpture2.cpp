#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2e4+10; 
int w[N],l[N],dp[N][N];
vector<int> ans;
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> w[i] >> l[i];

    forr(i,0,n+1)forr(j,1,n+1)dp[i][j] = 1e9;
    // forr(i,0,n)dp[i][0] = 0;
    forr(j,1,n+1){
        forr(i,1,n){
            forr(k,0,i){
                if(l[i]<dp[k][j-1])continue;
                dp[i][j] = min(dp[i][j],dp[k][j-1]+w[i]);
            }
        }
    }

    forr(i,1,n+1)cout << dp[n-1][i] << sp;

    return 0;
}