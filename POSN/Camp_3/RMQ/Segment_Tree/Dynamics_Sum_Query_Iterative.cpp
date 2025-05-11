#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
ll n,q,a,b,x,cmd;

struct Segment{
    ll seg[4*N];

    void update(ll idx, ll val){
        idx += n;
        seg[idx] = val;
        for(ll i=idx>>1;i>=1;i>>=1)seg[i] = seg[i<<1] + seg[(i<<1)+1];
    }

    ll query(ll a, ll b){
        ll sum = 0;
        for(a+=n,b+=n;a<=b;a>>=1,b>>=1){
            if(a&1)sum += seg[a++];
            if(!(b&1))sum += seg[b--];
        }
        return sum;
    }
}seg;

int main(){macos;

    cin >> n >> q;
    forr(i,1,n+1)cin >> x,seg.update(i,x);
    while(q--){
        cin >> cmd >> a >> b;
        if(cmd==1)seg.update(a,b);
        else cout << seg.query(a,b) << endll;
    }

    return 0;
}