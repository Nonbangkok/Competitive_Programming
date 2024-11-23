#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int m,n,dp[100][100];
char table[100][100];

int cp(int i,int j){
    if(i==0&&j==0)return 1;
    if(table[i][j]=='#'||i<0||j<0)return 0;
    if(dp[i][j]!=0)return dp[i][j];
    return dp[i][j]=cp(i-1,j)+cp(i,j-1);
}

int main() {macos;

    cin  >> m >> n;
    forr(i,0,m){
        forr(j,0,n){
            cin >> table[i][j];
        }
    }
    cout << cp(m-1,n-1);

    return 0;
 }