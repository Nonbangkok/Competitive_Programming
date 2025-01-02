#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5+10;
int pre,now = 1;
int A[N];
ll dp[2][4][4][4][4],n,mx;
char ch;

ll coal(int a,int b,int c){
    ll sum=0;
    if(a==1||b==1||c==1)sum++;
    if(a==2||b==2||c==2)sum++;
    if(a==3||b==3||c==3)sum++;
    return sum;
}

int main(){macos;

    cin >> n;
    forr(i,1,n+1){
        cin >> ch;
        if(ch=='M')A[i] = 1;
        else if(ch=='F')A[i] = 2;
        else A[i] = 3;
    }

    dp[pre][A[1]][0][0][0] = dp[pre][0][0][A[1]][0] = 1;
    forr(i,2,n+1){
        forr(j,0,4)forr(k,0,4)forr(l,0,4)forr(o,0,4){
            if(!dp[pre][j][k][l][o])continue;
            dp[now][A[i]][j][l][o] = max(dp[now][A[i]][j][l][o],dp[pre][j][k][l][o]+coal(A[i],j,k));
            dp[now][j][k][A[i]][l] = max(dp[now][j][k][A[i]][l],dp[pre][j][k][l][o]+coal(A[i],l,o));
        }
        swap(pre,now);
    }

    forr(j,0,4)forr(k,0,4)forr(l,0,4)forr(o,0,4)mx = max(mx,dp[pre][j][k][l][o]);
    cout << mx;

    return 0;
}
