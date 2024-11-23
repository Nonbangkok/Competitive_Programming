#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const ll M=1e18+7;
ll dp[2][3];
int main(){macos;

    ll n,now=1,prev=0;
    cin >> n;
    dp[prev][0]=dp[prev][1]=1;
    forr(i,1,n+1){
        dp[now][0]=(dp[prev][0]+dp[prev][1])%M;
        dp[now][1]=(dp[prev][0])%M;
        dp[now][2]=(2*dp[prev][2]+dp[prev][1])%M;
        swap(prev,now);
    }
    cout<< dp[now][2];

    return 0;
}