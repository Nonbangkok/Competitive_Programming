#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1001,MOD=1e9+7;
ll dp[N][N];
pair<int,int> table[N][N];
int main(){macos;

    int n,m,c;
    cin >> n >> m >> c;

    forr(i,0,c){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        table[c][d]={a,b};
    }
    
    dp[1][1]=1;
    forr(i,1,n+1){
        forr(j,1,m+1){
            dp[i][j]+=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=MOD;
            if(table[i][j].first!=0){
                dp[i][j]+=dp[table[i][j].first][table[i][j].second];
                dp[i][j]%=MOD;
            }
        }
    }
    cout << dp[n][m];

    return 0;
}