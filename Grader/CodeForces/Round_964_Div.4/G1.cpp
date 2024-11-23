#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e5+10;
int dp[N];

int log3(int n){
    int cnt = 0;
    while(n){
        n/=3;
        cnt++;
    }
    return cnt;
}

int main(){macos;

    int t;
    cin >> t;

    forr(i,1,N)dp[i]+=dp[i-1]+log3(i);

    while(t--){
        int l,r;
        ll sum = 0;
        cin >> l >> r;
        // cout << (dp[r]-dp[l-1])+dp[l]-dp[l-1] << endll;
        cout << dp[r]+dp[l]-2*dp[l-1] << endll;
    }

    return 0;
}