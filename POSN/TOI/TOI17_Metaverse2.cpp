#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    ll ar,ac,br,bc;
};

const int N = 20010;
ll n,m,k,p,ans = 1e18,cnt = 1e18;
ll dp[N][20];
Non node[N];

void fastscan(ll &x){
    int c=getchar();
    for(x=0;'0'<=c&&c<='9';c=getchar())x=(x*10)+(c-'0');
}

int main(){macos;

    fastscan(n);fastscan(m);fastscan(k);fastscan(p);
    forr(i,1,k+1){
        fastscan(node[i].ar);fastscan(node[i].ac);fastscan(node[i].br);fastscan(node[i].bc);
        dp[i][1] = node[i].ar + node[i].ac - 2;

        ll dis = dp[i][1]+abs(n-node[i].br) + abs(m-node[i].bc);
        if(ans > dis)ans = dis,cnt = 1;
        else if(ans == dis)cnt = min(cnt,1LL);
    }

    forr(l,2,p+1)forr(i,1,k+1){
        dp[i][l] = 1e18;
        forr(j,1,k+1)if(i!=j)
        dp[i][l] = min(dp[i][l],dp[j][l-1] + abs(node[j].br-node[i].ar) + abs(node[j].bc-node[i].ac));

        ll dis = dp[i][l]+abs(n-node[i].br) + abs(m-node[i].bc);
        if(ans > dis)ans = dis,cnt = l;
        else if(ans == dis)cnt = min(cnt,(ll)l);
    }

    cout << ans << sp << cnt;

    return 0;
}