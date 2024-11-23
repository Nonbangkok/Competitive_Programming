#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int M=1e9+7;
int m,n,dp[100][100];

int cp(int i,int j){
    if(i==0&&j==0)return 1;
    if(i<0||j<0)return 0;
    if(dp[i][j]!=0)return dp[i][j];
    return dp[i][j]=cp(i-1,j)%M+cp(i,j-1)%M;
}

int main() {macos;

    int t;
    cin >> t;
    while(t--){
        cin  >> m >> n;
        cout << cp(m-1,n-1)%M << endll;
        memset(dp,0,sizeof(dp));
    }

    return 0;
 }