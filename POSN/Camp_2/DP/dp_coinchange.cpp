#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int dp[1000];

int change(int n){
    if(n==0)return 0;
    if(n<0)return 1e9;
    if(dp[n]!=0)return dp[n];
    return dp[n]=1+min(change(n-1),min(change(n-3),change(n-4)));
}

int main() {macos;

    int n;
    cin >> n;
    cout <<change(n);

    return 0;
 }