#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 20;
int n,m;
int a[N],b[N];
pair<int,int> dp[1<<N];

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)cin >> a[i];
    forr(i,0,m)cin >> b[i];

    dp[0] = {0,0};
    forr(i,1,1<<m){
        dp[i] = {-1,-1};
        forr(k,0,m){
            if(!(i&(1<<k)))continue;
            int j = i ^ (1<<k);
            if(dp[j].first==-1)continue;
            if(dp[j].second+b[k]==a[dp[j].first])
                dp[i] = {dp[j].first+1,0};
            else if(dp[j].second+b[k]<a[dp[j].first])
                dp[i] = {dp[j].first,dp[j].second+b[k]};
        }
        if(dp[i].first==n){cout << "YES";return 0;}
    }
    cout << "NO";

    return 0;
}