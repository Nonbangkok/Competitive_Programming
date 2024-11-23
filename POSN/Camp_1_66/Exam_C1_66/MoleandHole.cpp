#include <iostream>
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=1001,K=501,M=1e9+7;
int dp[N][K];

int cnr(int i,int j){
    if(j==0||i==j)return 1;
    if(dp[i][j]!=0)return dp[i][j];
    return dp[i][j]=(cnr(i-1,j-1)+cnr(i-1,j))%M;
}
int main() {macos;

    int n,k,r;
    cin >> n >> k;
    r=n;
    n=n+k-1;
    cout << cnr(n,r);

    return 0;
 }