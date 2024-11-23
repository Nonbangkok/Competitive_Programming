#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,k;
    cin >> n >> k;
    int A[n],dp[n];
    forr(i,0,n)cin >> A[i];

    deque<pair<int,int>> q;
    q.push_back({A[0],0});
    dp[0]=A[0];

    forr(i,1,n){
        while(!q.empty()&&q.front().second<i-k)q.pop_front();
        dp[i]=A[i]+q.front().first;
        while(!q.empty()&&q.back().first>dp[i])q.pop_back();
        q.push_back({dp[i],i});
    }
    cout << dp[n-1];

    return 0;
 }