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
const int mp[3][3]={{2,1,0},{2,1,1},{1,2,1}};
int n;
bool dp[N][N][3];
string s;
int main(){macos;

    forr(i,0,20){
        cin >> n >> s;
        memset(dp,0,sizeof(dp));
        forr(i,0,n)dp[i][i][s[i]-'0']=1;
        forr(sz,1,n)forr(l,0,n-sz){
            int r=l+sz;
            forr(k,l,r)forr(i,0,3)forr(j,0,3)if(dp[l][k][i]&&dp[k+1][r][j])dp[l][r][mp[i][j]]=1;
        }
        cout << (dp[0][n-1][0]?"yes":"no") << endll;
    }

    return 0;
}