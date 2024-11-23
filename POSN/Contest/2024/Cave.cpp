#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=101;
ll A[N][N],dp1[N][N],dp2[N][N];
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,1,n+1)forr(j,1,m+1)cin >> A[i][j];
    forr(i,0,n+2){dp1[i][0]=dp1[i][m+1]=dp2[i][0]=dp2[i][m+1]=-1;}
    forr(j,0,m+2){dp1[0][j]=dp1[n+1][j]=dp2[0][j]=dp2[n+1][j]=-1;}

    ll temp=A[1][m];
    forr(j,2,m+1)A[1][j]=-1;

    forr(i,1,n+1){
        forr(j,1,m+1){
            if(i==1&&j==1){dp1[i][j]=A[i][j];continue;}
            int temp=max(dp1[i-1][j-1],max(dp1[i-1][j],dp1[i-1][j+1]));
            if(temp==-1)dp1[i][j]=-1;
            else dp1[i][j]=A[i][j]+max(dp1[i-1][j-1],max(dp1[i-1][j],dp1[i-1][j+1]));
        }
    }

    A[1][m]=temp;
    A[1][1]=-1;

    forr(i,1,n+1){
        forr(j,1,m+1){
            if(i==1&&j==m){dp2[i][j]=A[i][j];continue;}
            int temp=max(dp2[i-1][j-1],max(dp2[i-1][j],dp2[i-1][j+1]));
            if(temp==-1)dp2[i][j]=-1;
            else dp2[i][j]=A[i][j]+max(dp2[i-1][j-1],max(dp2[i-1][j],dp2[i-1][j+1]));
        }
    }

    ll mx1=-1,mx2=-1;
    forr(i,1,m+1){
        if(dp1[n][i]==-1)continue;
        mx1=max(mx1,dp1[n][i]);
        dp1[n][i]=mx1;
    }
    forl(i,m,0){
        if(dp2[n][i]==-1)continue;
        mx2=max(mx2,dp2[n][i]);
        dp2[n][i]=mx2;
    }

    mx1=-1;
    forr(i,1,m){
        if(dp1[n][i]==-1||dp2[n][i+1]==-1)continue;
        mx1=max(mx1,dp1[n][i]+dp2[n][i+1]);
    }

    cout << mx1;

    // forr(i,1,n+1){
    //     forr(j,1,m+1){
    //         cout << setw(2) << dp1[i][j] << sp;
    //     }
    //     cout << endll;
    // }
    // cout << endll;
    // forr(i,1,n+1){
    //     forr(j,1,m+1){
    //         cout << setw(2) << dp2[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    return 0;
}