#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 4010;
int n,idx,mx;
int a[N],dp[N][N];
map<int,int> mp;

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> a[i];
    forr(i,1,n+1)if(mp.find(a[i])==mp.end())mp[a[i]] = idx++;
    forr(i,1,n+1)a[i] = mp[a[i]];
    forr(i,1,n+1)forr(j,1,n+1)dp[i][j] = 1;
    forr(i,1,n+1)forr(j,0,i){
        dp[i][a[j]] = max(dp[i][a[j]],dp[j][a[i]]+1);
        mx = max(mx,dp[i][a[j]]);
    }

    cout << mx;

    return 0;
} 