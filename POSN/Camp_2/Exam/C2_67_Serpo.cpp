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
    int u,v;
    ll w;

    bool operator < (const Non &rhs)const{
        return w>rhs.w;
    }
};

const int N = 1e5 + 10;
int n,m,a,b;
ll c,ans;
int p[N];
priority_queue<Non> q;

int fp(int x){
    if(p[x] != x)p[x] = fp(p[x]);
    return p[x];
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        q.push({a,b,c});
    }

    forr(i,1,n+1)p[i] = i;

    while(!q.empty()){
        auto [u,v,w] = q.top();
        q.pop();

        if(fp(u)==fp(v))continue;
        p[fp(u)] = fp(v);
        ans += w;
    }

    cout << ans;
    
    return 0;
}