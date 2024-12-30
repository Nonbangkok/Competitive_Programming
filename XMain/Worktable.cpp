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
    int a,b,c,d;
};

const int N = 2e4+10;
int n,m,k,p,a,b,c,d,mn,mnt;
int dp[N][20];
Non node[N];

int main(){macos;

    cin >> n >> m >> k >> p;
    forr(i,0,k){
        cin >> a >> b >> c >> d;
        node[i] = {a,b,c,d};
        forr(j,2,p+1)dp[i][j] = 1e9;
        dp[i][1] = node[i].a+node[i].b-2;
    }

    mn = m+n-2 ,mnt = 0;
    forr(t,1,p+1)forr(i,0,k){
        if(t!=1)forr(j,0,k)if(i!=j)dp[i][t] = min(dp[i][t],dp[j][t-1]+abs(node[j].c-node[i].a)+abs(node[j].d-node[i].b));
        if(mn>dp[i][t]+m+n-(node[i].c+node[i].d)){
            mn=dp[i][t]+m+n-(node[i].c+node[i].d);
            mnt=t;
        }
    }

    cout << mn << sp << mnt;

    return 0;
}