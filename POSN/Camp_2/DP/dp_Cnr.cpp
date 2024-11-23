#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int dp[1000][1000];
int cnr(int n,int r){
    if(r==0||n==r)return 1;
    if(dp[n][r]!=0)return dp[n][r];
    return dp[n][r]=cnr(n-1,r-1)+cnr(n-1,r);
}

int main() {macos;

    int n,r;
    cin >> n >> r;
    cout << cnr(n,r);

    return 0;
 }
