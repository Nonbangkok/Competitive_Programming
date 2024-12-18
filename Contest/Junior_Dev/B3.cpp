#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 5e5+10 ,M=1e9+7;
ll dp[N];
int main(){macos;

    ll n;
    cin >> n;

    forr(i,1,4)dp[i]=i;
    forr(i,4,5e5+1)dp[i]=(4*dp[i-1]+3*dp[i-2]+2*dp[i-3]+1)%M;

    while(n--){
        ll temp;
        cin >> temp;
        cout << dp[temp] << endll;
    }

    return 0;
}