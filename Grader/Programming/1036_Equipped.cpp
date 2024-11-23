#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int dp[1<<8];
int main(){macos;

    forr(i,0,(1<<8))dp[i]=INT_MAX;
    int n,m,x,mask,p;
    cin >> n >> m;
    forr(i,0,n){
        mask=0;
        cin >> x;
        forr(i,0,m){
            cin >> p;
            if(p)mask|=(1<<i);
        }
        dp[mask]=min(dp[mask],x);
    }
    //forr(i,0,1<<m)cout<< dp[i] << sp; cout << endll;
    forr(i,0,(1<<m)){
        forr(j,0,i){
            if(dp[j]==INT_MAX)continue;
            forr(k,0,j){
                if(dp[k]==INT_MAX)continue;
                if((j|k)==i)dp[i]=min(dp[i],dp[j]+dp[k]);
            }
        }
    }
    cout << dp[(1<<m)-1];

    return 0;
}