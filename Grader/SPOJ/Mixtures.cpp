#include <bits/stdc++.h>
#include <unistd.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=100;
pair<ll,ll> dp[N][N];//smoke,color
int main(){macos;

    int n;
    while(cin >> n){
        forr(i,0,n)forr(j,0,n)dp[i][j]={1e9,1e9};
        forr(i,0,n)cin >> dp[i][i].second,dp[i][i].first=0;
        forr(sz,1,n)forr(l,0,n-sz){
            int r=l+sz;
            forr(k,l,r){
                if(dp[l][r].first>dp[l][k].second*dp[k+1][r].second+dp[l][k].first+dp[k+1][r].first){
                    dp[l][r].first=dp[l][k].second*dp[k+1][r].second+dp[l][k].first+dp[k+1][r].first;
                    dp[l][r].second=(dp[l][k].second+dp[k+1][r].second)%N;
                }
            }
        }
        cout << dp[0][n-1].first << endll;
    }

    return 0;
}