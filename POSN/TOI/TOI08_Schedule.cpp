#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1010;
pair<int,int> dp[N][N];
int A[N],B[N];
int n,m;

pair<int,int> cal(pair<int,int> a,int b){
    if(a.second+b>m)return {a.first+1,b};
    return {a.first,a.second+b};
}

int main(){macos;

    cin >> m >> n;
    forr(i,1,n+1)cin >> A[i];
    forr(i,1,n+1)cin >> B[i];

    forr(i,0,n+1)forr(j,0,n+1){
        if(i==0&&j==0)continue;
        dp[i][j] = {1e9,1e9};
        if(i)dp[i][j] = min(dp[i][j],cal(dp[i-1][j],A[i]));
        if(j)dp[i][j] = min(dp[i][j],cal(dp[i][j-1],B[j]));
    }

    cout << dp[n][n].first+(dp[n][n].second>0) << endll << dp[n][n].second;

    return 0;
}