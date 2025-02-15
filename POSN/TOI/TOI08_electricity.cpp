#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5e5+10;
int dp[N],A[N];
int n,k;
deque<pair<int,int>> dq;

int main(){macos;

    cin >> n >> k;
    forr(i,0,n)cin >> A[i];

    dq.push_back({0,A[0]});

    forr(i,1,n){
        while(!dq.empty()&&i-dq.front().first>k)dq.pop_front();
        dp[i] = dq.front().second + A[i];
        while(!dq.empty()&&dp[i]<=dq.back().second)dq.pop_back();
        dq.push_back({i,dp[i]});
    }

    cout << dp[n-1];

    return 0;
}