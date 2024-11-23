#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll n,m,c[101];
bool chk=true;

ll solve(ll p,ll w){
    if(p==1)return w;
    ll tmp=2*w-c[p-1]+1;
    if(tmp<=1){chk=false;return -1;}
    if(tmp&1)return solve(p-1,tmp/2)+solve(p-1,(tmp+1)/2);
    return 2*solve(p-1,(tmp/2));
}

int main(){macos;

    cin >> n >> m;
    forr(i,1,n)cin >> c[i];
    ll ans=solve(n,m);
    cout << (chk?ans:-1);

    return 0;
}