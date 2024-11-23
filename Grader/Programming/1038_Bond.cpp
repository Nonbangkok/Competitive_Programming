#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 21;
double A[N][N],dp[(1<<N)];

int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n+1)forr(j,1,n+1)cin >> A[i][j],A[i][j]/=100.0;
    
    dp[0]=1.0;
    forr(i,1,1<<n){
        int day = 0;
        forr(j,0,n)if(i&(1<<j))day++;
        forr(j,0,n)if(i&(1<<j))dp[i]=max(dp[i],dp[i^(1<<j)]*A[day][j+1]);
    }

    coutf(12,(double)dp[(1<<n)-1]*100.0);

    return 0;
}