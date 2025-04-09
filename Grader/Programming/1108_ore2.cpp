#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6 + 10;
ll n,k;
ll qs[N],dp[N];
deque<pair<int,ll>> dq;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> qs[i],qs[i] += qs[i-1];

    // forr(i,1,n+1){
    //     forr(j,0,i){
    //         if(qs[i]-qs[j]>k)continue;
    //         dp[i] = max(dp[i],dp[max(0,j-1)]+qs[i]-qs[j]);
    //     }
    //     dp[i] = max(dp[i],dp[i-1]);
    // }

    dq.push_back({0,0});
    forr(i,1,n+1){
        while(!dq.empty()&&k+qs[dq.front().first]<qs[i])dq.pop_front();
        if(!dq.empty())dp[i] = qs[i] + dq.front().second;
        while(!dq.empty()&&dq.back().second<=dp[i-1]-qs[i])dq.pop_back();
        dq.push_back({i,dp[i-1]-qs[i]});
        dp[i] = max(dp[i],dp[i-1]);
    }

    // forr(i,1,n+1)cout << dp[i] << sp;cout << endll;
    cout << dp[n];

    return 0;
}