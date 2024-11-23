#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int m=1e9+7;
int n,k,d;
bool visited[302][302][11];
ll dp[302][302][11],A[302];

ll mcm(int l,int r,int depth){
    if(depth==k-1)return 1;
    if(visited[l][r][depth])return dp[l][r][depth];
    visited[l][r][depth]=true;
    forr(j,l,r)if(abs((A[r]-A[j])-(A[j]-A[l-1]))<=d)dp[l][r][depth]=(dp[l][r][depth]+(((visited[l][j][depth+1]?dp[l][j][depth+1]:mcm(l,j,depth+1))*(visited[j+1][r][depth+1]?dp[j+1][r][depth+1]:mcm(j+1,r,depth+1)))%m))%m;
    return dp[l][r][depth];
}

int main() {macos;

    cin >> n >> k >> d;
    forr(i,0,n)cin >> A[i];
    forr(i,1,n)A[i]+=A[i-1];
    cout << mcm(0,n-1,0);

    return 0;
}