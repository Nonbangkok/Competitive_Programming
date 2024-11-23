#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,dp[256][256][3];
bool visited[256][256][3];
string s;

bool segi(int i,int j,int x){
    if(visited[i][j][x])return dp[i][j][x];
    visited[i][j][x]=1;
    if(i==j){
        if(s[i]-'0'==x)dp[i][j][x]=1;
        return dp[i][j][x];
    }
    forr(k,i,j+1){
        if(x==0){
            if(segi(i,k,0)&&segi(k+1,j,2)){dp[i][j][x]=1;break;}
        }else if(x==1){
            if(segi(i,k,0)&&segi(k+1,j,1)){dp[i][j][x]=1;break;}
            if(segi(i,k,1)&&segi(k+1,j,1)){dp[i][j][x]=1;break;}
            if(segi(i,k,1)&&segi(k+1,j,2)){dp[i][j][x]=1;break;}
            if(segi(i,k,2)&&segi(k+1,j,0)){dp[i][j][x]=1;break;}
            if(segi(i,k,2)&&segi(k+1,j,2)){dp[i][j][x]=1;break;}
        }else if(x==2){
            if(segi(i,k,0)&&segi(k+1,j,0)){dp[i][j][x]=1;break;}
            if(segi(i,k,1)&&segi(k+1,j,0)){dp[i][j][x]=1;break;}
            if(segi(i,k,2)&&segi(k+1,j,1)){dp[i][j][x]=1;break;}
        }
    }
    return dp[i][j][x];
}

int main() {macos;

    int t=20;
    while(t--){
        cin >> n >> s;
        (segi(0,n-1,0))? cout << "yes":cout << "no";
        cout << endll;
        memset(dp,0,sizeof(dp));
        memset(visited,0,sizeof(visited));
    }

    return 0;
}