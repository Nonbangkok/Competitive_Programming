#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//LCS
string v,p;
int n;
int solve(int vn,int pn){
    int dp[vn+2][pn+2];
    forr(i,0,vn+1){
        forr(j,0,pn+1){
            if(!i||!j)dp[i][j]=0;
            else{
                if(v[i-1]!=p[j-1])dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j-1]+1;
            }
        }
    }
    return dp[vn][pn];
}

int main() {macos;

    cin >> v >> n;
    while(n--){
        cin >> p;
        cout << solve(v.size(),p.size()) << endll;
    }

    return 0;
}