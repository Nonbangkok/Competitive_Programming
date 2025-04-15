#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5e5 + 10;
ll n,k;
ll p[N],dp[N];
deque<int> dq;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> p[i];

    dq.push_back(1);
    dp[1] = p[1];
    forr(i,2,n+1){
        while(!dq.empty()&&i-dq.front()>k)dq.pop_front();
        dp[i] = p[i] + dp[dq.front()];
        while(!dq.empty()&&dp[i]<=dp[dq.back()])dq.pop_back();
        dq.push_back(i);
    }

    cout << dp[n];

    return 0;
}