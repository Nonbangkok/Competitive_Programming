#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1001,M=1e9+7;
ll dp[N][5001],A[N],n,k;

ll solve(int i,ll sum){
    if(i==n)return sum==k;
    if(dp[i][sum]!=-1)return dp[i][sum];
    return dp[i][sum]=(solve(i+1,sum+A[i])+solve(i+1,sum-A[i]))%M;
}

int main(){macos;

    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    forr(i,0,n)cin >> A[i];
    cout << solve(0,0);

    // forr(i,0,n+1){
    //     forr(j,-5,5){
    //         cout << setw(2)<< dp[i][j] << sp; 
    //     }
    //     cout << endll;
    // }

    return 0;
}