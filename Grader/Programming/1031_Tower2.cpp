#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e4 + 10;
int k,n,m,a,b,ans;
int dp[N];
vector<int> adj[N];

int main(){macos;

    cin >> k >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    forr(i,2,n+1)dp[i] = 1e9;
    forr(i,1,n+1){
        for(int j:adj[i])dp[j] = min(dp[j],dp[i]+1);
        if(dp[i]<=k)ans = i;
    }
    
    cout << ans;

    return 0;
}