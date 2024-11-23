#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e2+10; 
int w[N],l[N],dp[N][N][2];

int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n+1)cin >> w[i] >> l[i];

    forr(i,1,n+1)forr(j,1,n+1)dp[i][j][0] = dp[i][j][1] = 1e9;
    forr(i,1,n+1)dp[i][1][0] = w[i];
    forr(j,1,n+1){
        forr(i,1,n+1){
            forr(k,1,i){
                forr(p,0,2){
                    if(l[i]>=dp[k][j-1][p]){
                        dp[i][j][p] = min(dp[i][j][p],min(dp[i-1][j][p],dp[k][j-1][p]+w[i]));
                        if(dp[i][j][0]!=1e9)dp[i][j][1] = 0;
                    }
                }
            }
        }
    }

    forr(i,1,n+1){
        forr(j,1,n+1){
            cout << setw(2);
            if(dp[i][j][1]==1e9)cout << '-' << sp;
            else cout << dp[i][j][1] << sp;
        }
        cout << endll;
    }
    cout << endll;

    forr(i,1,n+1){
        cout << setw(2);
        if(dp[n][i][0]==1e9)cout << '-' << sp;
        else cout << dp[n-1][i][0] << sp;
    }
    cout << endll;
    forr(i,1,n+1){
        cout << setw(2);
        if(dp[n][i][1]==1e9)cout << '-' << sp;
        else cout << dp[n-1][i][1] << sp;
    }

    forl(i,n,0){
        if(dp[n][i][0]!=1e9||dp[n][i][1]!=1e9){
            cout << i;
            break;
        }
    }

    return 0;
}