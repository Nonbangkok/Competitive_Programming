#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 50;
ll dp[N][N];
int n,m;

int knight(int i,int j){
    if(i<0||j<0||i>=n||j>=m)return 0;
    if(dp[i][j])return dp[i][j];
    if((i==1&&j==2)||(i==2&&j==1))return dp[i][j]=1;
    return dp[i][j]=knight(i-1,j-2)+knight(i-2,j-1)+knight(i+1,j-2)+knight(i-2,j+1);
}

int main() {macos;

    cin >> n >> m;
    cout << knight(n-1,m-1);

    return 0;
}