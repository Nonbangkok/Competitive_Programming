#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int M = 1e9 + 7;
int n,ka,kb,kc;
int pre,now = 1;
ll dp[2][3][1010][8],ans;

int main(){macos;

    cin >> n >> ka >> kb >> kc;

    dp[0][0][0][1] = 1LL;
    forr(i,0,n){
        forr(j,0,3)forr(k,0,1010)forr(l,0,8)dp[now][j][k][l] = 0LL;
        forr(j,1,ka+1){
            forr(k,0,8){
                dp[now][0][j][k] += dp[pre][0][j-1][k]; // พักต่อ ถ้าไม่เกินวัน
                dp[now][1][0][k|(1<<1)] += dp[pre][0][j-1][k]; // a -> b
                dp[now][2][0][k|(1<<2)] += dp[pre][0][j-1][k]; // a -> c
            }
        }
        forr(j,1,kb+1){
            forr(k,0,8){
                dp[now][1][j][k] += dp[pre][1][j-1][k]; // พักต่อ ถ้าไม่เกินวัน
                dp[now][2][0][k|(1<<2)] += dp[pre][1][j-1][k]; // b -> c
            }
        }
        forr(j,1,kc+1){
            forr(k,0,8){
                dp[now][2][j][k] += dp[pre][2][j-1][k]; // พักต่อ ถ้าไม่เกินวัน
                dp[now][0][0][k|(1<<0)] += dp[pre][2][j-1][k]; // c -> a
            }
        }
        swap(pre,now);
    }

    forr(i,0,3)forr(j,0,1010){
        ans += dp[pre][i][j][7];
        // if(dp[pre][i][j][7])cout << dp[pre][i][j][7] << sp;
        if(dp[pre][i][j][7])cout << i << sp << j << sp << dp[pre][i][j][7] << endll;
    }
    cout << endll;
    cout << ans;

    return 0;
}