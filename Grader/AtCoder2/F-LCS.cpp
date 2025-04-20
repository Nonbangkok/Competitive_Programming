#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 3010;
int n,m;
int dp[N][N];
string a,b,ans;

int main(){macos;

    cin >> a >> b;
    n = a.size(), m = b.size();

    forr(i,1,n+1)forr(j,1,m+1){
        if(a[i-1]==b[j-1])dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }

    int i = n, j = m;
    while(i&&j){
        if(dp[i][j]>dp[i-1][j]&&dp[i][j]>dp[i][j-1])ans.push_back(a[i-1]),i--,j--;
        else if(dp[i][j]==dp[i-1][j])i--;
        else j--;
    }

    reverse(ans.begin(),ans.end());

    cout << ans;


    return 0;
}