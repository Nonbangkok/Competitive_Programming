#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
char ch[1001];
int dp[1001][1001];

int four(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(l==r)return 0;
    if(l+1==r&&ch[l]==ch[r])return dp[l][r]=1;
    else if(l+1==r) return dp[l][r]=0;
    else if(ch[l]==ch[r])return dp[l][r]=four(l+1,r-1)+1;
    else forr(i,l,r)dp[l][r]=max(dp[l][r],four(l,i)+four(i+1,r));
    return dp[l][r];
}

int main() {macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> ch[i];
    forr(i,0,1000)forr(j,0,1000)dp[i][j]=-1;
    cout << four(0,n-1);

    return 0;
}