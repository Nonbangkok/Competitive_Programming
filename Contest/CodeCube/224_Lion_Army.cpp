#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 3e5+10,M = 1e9+7;
int p[N],n,m,x,u,v,cnt;
ll ans,a;
bool chk;

int fp(int x){
    if(x!=p[x])p[x] = fp(p[x]);
    return p[x];
}

int solve(){
    cin >> x >> u >> v;
    if(chk)return 0;
    if(u>v)swap(u,v);
    if(fp(u)!=fp(v)){
        p[fp(v)] = fp(u);
        
    }else if((x&&)||(!x&&)){
        chk = true;
        return 0;
    }
    a = 2,cnt = 0,ans = 1;
    forr(i,1,n+1)cnt += (i == p[i]);
    while(cnt){
        if(cnt&1)ans = (ans*a) %M;
        a = (a*a) %M;
        cnt >>= 1;
    }
    return ans;
}

int main(){macos;

    cin >> n >> m;

    forr(i,1,n+1)p[i] = i;
    while(m--){
        cout << solve() << endll;
    }

    return 0;
}