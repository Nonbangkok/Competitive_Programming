#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
vector<int> A;
int dp[1000000],n;

int solve(int i){
    if(i==0)return 0;
    if(i<0)return 1e9;
    if(dp[i])return dp[i];
    dp[i]=INT_MAX;
    forr(j,0,n)dp[i]=min(dp[i],1+solve(i-A[j]));
    return dp[i];
}

int main(){macos; 

    int t,a,coin;
    cin >> coin >> n;
    forr(i,0,n){
        cin >> a;
        A.push_back(a);
    }
    cout << solve(coin);

	return 0;
}