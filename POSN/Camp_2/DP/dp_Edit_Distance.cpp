#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//Cses.fi
int dp[5002][5002];
string a,b;

int edit(int i,int j){
    if(i==-1)return j+1;
    if(j==-1)return i+1;
    if(dp[i][j])return dp[i][j];
    if(a[i]==b[j])dp[i][j]=edit(i-1,j-1);
    else dp[i][j]=min(1+edit(i-1,j),min(1+edit(i,j-1),1+edit(i-1,j-1)));
    return dp[i][j];
}

int main(){macos;

    cin >> a >> b;
    cout << edit(a.size()-1,b.size()-1);

    return 0;
}