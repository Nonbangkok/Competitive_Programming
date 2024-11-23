#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=256;
int m,dp[N][N][3];
string s;

int segi(int l,int r,int n){
    if(dp[l][r][n]!=-1)return dp[l][r][n];
    if(l==r)return dp[l][r][n]=(s[l]-'0'==n);
    forr(k,l,r){
        if(n==0){
            if(segi(l,k,0)&&segi(k+1,r,2))return dp[l][r][n]=1;
        }else if(n==1){
            if(segi(l,k,0)&&segi(k+1,r,1))return dp[l][r][n]=1;
            if(segi(l,k,1)&&segi(k+1,r,1))return dp[l][r][n]=1;
            if(segi(l,k,1)&&segi(k+1,r,2))return dp[l][r][n]=1;
            if(segi(l,k,2)&&segi(k+1,r,0))return dp[l][r][n]=1;
            if(segi(l,k,2)&&segi(k+1,r,2))return dp[l][r][n]=1;
        }else if(n==2){
            if(segi(l,k,0)&&segi(k+1,r,0))return dp[l][r][n]=1;
            if(segi(l,k,1)&&segi(k+1,r,0))return dp[l][r][n]=1;
            if(segi(l,k,2)&&segi(k+1,r,1))return dp[l][r][n]=1;
        }
    }
    return dp[l][r][n]=0;
}

int main(){macos;

    forr(l,0,20){
        forr(i,0,256)forr(j,0,256)forr(k,0,3)dp[i][j][k]=-1;
        cin >> m >> s;
        cout << (segi(0,m-1,0)?"yes":"no") << endll; 
    }

    return 0;
}