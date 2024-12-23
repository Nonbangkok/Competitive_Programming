#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int M = 1e9+7;
int n,k,d;
ll dp[10][310][310],qs[310];

int main(){macos;

    cin >> n >> k >> d;
    forr(i,1,n+1){
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }
    forr(i,1,n+1)forr(j,1,n+1)dp[1][i][j] = 1LL;
    forr(depth,2,k+1){
        forr(sz,1,n)forr(l,1,n+1-sz){
            int r = l+sz;
            forr(k,l,r){
                if(abs(qs[r]-2*qs[k]+qs[l-1])>d)continue;
                dp[depth][l][r] = (dp[depth][l][r] + dp[depth-1][l][k]*dp[depth-1][k+1][r]) % M;
            }
        }
    }

    cout << dp[k][1][n];

    return 0;
}