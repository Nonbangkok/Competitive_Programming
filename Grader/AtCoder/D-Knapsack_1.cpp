#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=101,M=1e5+10;
int n,w,W[N];
ll V[N],dp[N][M];

ll solve(int i,int j){
    if(i==n)return 0;
    if(dp[i][j])return dp[i][j];
    if(W[i]>j)return dp[i][j]=solve(i+1,j);
    return dp[i][j]=max(solve(i+1,j),V[i]+solve(i+1,j-W[i]));
}

int main(){macos;

    cin >> n >> w;
    forr(i,0,n)cin >> W[i] >> V[i];
    cout << solve(0,w);

    return 0;
}