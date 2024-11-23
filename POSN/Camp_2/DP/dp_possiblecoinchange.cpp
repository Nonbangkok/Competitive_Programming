#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int t,n,A[301],dp[301],coin;

int nonbk(int c){
    if(c<0)return 0;
    if(dp[c]!=0)return dp[c];
    if(c==0)return dp[c]=1;
    forr(i,0,n){
        dp[c]+=nonbk(c-A[i]);
    }
    return dp[c];
}

int main() {macos;

    cin >> t;
    while(t--){
        cin >> n;
        forr(i,0,n){
            cin >> A[i];
        }
        cin >> coin;
        cout << nonbk(coin) << endll;
        memset(dp,0,sizeof(dp));
    }
    //not finished yet

    return 0;
 }