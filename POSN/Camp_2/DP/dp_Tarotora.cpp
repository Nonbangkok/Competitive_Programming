#include <iostream>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1002;
int A[N],B[N],dp[N][204],t,k,n;

int nonbk(int i,int d){
    if(i==n+1)return 0;
    if(d<0||d>k*2)return (int)1e6;
    if(dp[i][d])return dp[i][d];
    return dp[i][d]=min(nonbk(i+1,d+1)+A[i],nonbk(i+1,d-1)+B[i]);
}

int main() {macos;

    cin >> t;
    while(t--){
        cin >> n >> k;
        forr(i,1,n+1)cin >> A[i] >> B[i];
        cout << nonbk(1,k) << endll;
        forr(i,0,100002)forr(j,0,204)dp[i][j]=0;
    }

    return 0;
 }

