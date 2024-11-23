#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
     
string s1,s2;
int t,n1,n2,dp[101][101];

int LCS(int i,int j){
    if(i==-1||j==-1)return 0;
    if(dp[i][j]!=0)return dp[i][j];
    if(s1[i]==s2[j])return dp[i][j]=LCS(i-1,j-1)+1;
    return dp[i][j]=max(LCS(i-1,j),LCS(i,j-1));
}

int main() {macos;


    cin >> t;
    while(t--){
        cin >> n1 >> n2 >> s1 >> s2;
        cout << LCS(n1-1,n2-1) << endll;
        memset(dp,0,sizeof(dp));
    }

    return 0;
 }
