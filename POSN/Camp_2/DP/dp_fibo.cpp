#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int dp[10000];
int fib(int n){
    if(n==0||n==1)return 1;
    if(dp[n]!=0)return dp[n];
    return dp[n]=fib(n-1)+fib(n-2);
}

int main() {macos;

    int n;
    cin >> n;
    cout << fib(n) << sp;


    return 0;
 }