#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e4+10;
int price[N],pages[N],dp[N*10];
int main(){macos;

    int n,x;
    cin >> n >> x;
    forr(i,0,n)cin >> price[i];
    forr(i,0,n)cin >> pages[i];

    forr(j,0,n)forl(i,x,0){
        if(i-price[j]<0)continue;
        dp[i]=max(dp[i],dp[i-price[j]]+pages[j]);
    }
    cout << dp[x];

    return 0;
}