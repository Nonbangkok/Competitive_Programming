#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int day,minute;

    bool operator < (const Non &rhs)const{
        if(day!=rhs.day)return day<rhs.day;
        return minute<rhs.minute;
    }
};

const int N=1010;
int A[N],B[N],k,n;
Non dp[N][N];

Non work(Non dp,int n){
    if(dp.minute+n<=k)return {dp.day,dp.minute+n};
    return {dp.day+1,n};
}

int main() {macos;

    cin >> k >> n;
    forr(i,1,n+1)cin >> A[i];
    forr(i,1,n+1)cin >> B[i];
    forr(i,0,n+1)forr(j,0,n+1)dp[i][j]={INT_MAX,INT_MAX};
    dp[0][0]={1,0};
    
    forr(i,0,n+1)forr(j,0,n+1){
        if(i&&j)dp[i][j]=min(work(dp[i-1][j],A[i]),work(dp[i][j-1],B[j]));
        else if(i)dp[i][j]=work(dp[i-1][j],A[i]);
        else if(j)dp[i][j]=work(dp[i][j-1],B[j]);
        //cout << i << sp << j << sp << dp[i][j].day << sp << dp[i][j].minute << endll;
    }
    cout << dp[n][n].day << endll << dp[n][n].minute;

    return 0;
}