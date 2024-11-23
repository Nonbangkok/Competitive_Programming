#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
ll fw[N],n,q,a,b,t,pos,w;

void update(ll idx,ll val){
    for(ll i=idx;i<=N;i+=(i&-i))fw[i]+=val;
}

ll query(ll idx){
    ll sum=0;
    for(ll i=idx;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}

ll find(ll k){
    ll l=1,r=n+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        
        if(query(mid)<k)r=mid;
        else l=mid+1;
    }
    return l;
}

int main(){macos;

    cin >> n >> q >> a >> b;
    while(q--){
        cin >> t >> pos >> w;
        if(t==1)update(1,w),update(pos+1,-w);
        else update(pos,-w),update(n+1,w);
        ll l=find(b+1),r=find(a)-1;
        if(l==r)cout << l << endll;
        else if(l<r)cout << l << sp << r << endll;
        else cout << -1 << endll;
    }

    return 0;
}