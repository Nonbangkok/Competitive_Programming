#include <iostream>
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define forr(i, a, n) for (int i = a; i < n; i++)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int M=1e9+7;
int dp[1001][501];
int main() {macos;

    int n,k,r;
    cin >> n >> k;
    r=n;
    n=n+k-1;
    //memset(dp,0,sizeof(dp));
    forr(i,0,n+1){
        forr(j,0,i+1){
            if(j==0||i==j)dp[i][j]=1;
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%M;
        }
    }
    cout << dp[n][r];

    return 0;
 }