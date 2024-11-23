#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int coins[110];
bool dp[110][100010];
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> coins[i];

    ll sum = accumulate(coins,coins+n,0LL);
    dp[0][0]=true;

    forr(i,1,n+1){
        forr(j,0,sum+1){
            dp[i][j] = dp[i-1][j];
            if(j-coins[i-1]>=0 && dp[i-1][j-coins[i-1]])dp[i][j] = true;
        }
    }

    vector<ll> ans;
    forr(i,1,sum+1)if(dp[n][i])ans.push_back(i);
    cout << ans.size() << endll;
    for(int i:ans)cout << i << sp;

    return 0;
}