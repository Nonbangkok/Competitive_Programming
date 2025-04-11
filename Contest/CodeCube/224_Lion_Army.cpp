#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2 * 3e5 + 10, M = 1e9 + 7;
int n,m,x,u,v,cnt;
int p[N];
ll ans,a;
ll dp[N >> 1];
bool chk;

int fp(int x){
    if(x!=p[x])p[x] = fp(p[x]);
    return p[x];
}

void dsu(int a, int b){
    a = fp(a), b = fp(b);
    if(a==b)return;
    p[b] = a;
    cnt--;
}

int main(){macos;

    cin >> n >> m;

    dp[0] = 1;
    forr(i,1,2*n+1)p[i] = i;
    forr(i,1,n+1)dp[i] = (dp[i-1] << 1) % M;
    cnt = n << 1;
    while(m--){
        cin >> x >> u >> v;
        if(x)dsu(u,v),dsu(u+n,v+n);
        else dsu(u+n,v),dsu(u,v+n);
        if(cnt&1)chk = true;
        if(chk)cout << 0 << endll;
        else cout << dp[cnt>>1] << endll;
    }

    return 0;
}