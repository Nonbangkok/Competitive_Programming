#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll dp[16][9];

ll cnk(ll i,ll j){
    if(j==0||i==j)return 1;
    if(dp[i][j])return dp[i][j];
    return dp[i][j]=cnk(i-1,j)+cnk(i-1,j-1);
}

int main(){macos;
    
    ll q,n,k;
    cin >> q;
    while(q--){
        cin >> n >> k;
        cout << cnk(n,k) << endll;
    }

    return 0;
}