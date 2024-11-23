#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
ll dp[20002];
int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n)cin >> dp[i];
    forr(i,1,n)dp[i]+=dp[i-1];
    ll mx=-1,x,y;
    forr(i,1,n){
        forr(j,i,n){
            if(mx<dp[j]-dp[i-1]||(mx==dp[j]-dp[i-1]&&y-x<j-i)){
                mx=dp[j]-dp[i-1];
                x=i;
                y=j;
            }
        }
    }
    mx>=0?cout << x << sp << y+1:cout << "no";

    return 0;
}