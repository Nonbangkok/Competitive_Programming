#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (ll i = a; i < n; i++)
#define forl(i, a, n) for (ll i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const ll N=2e5+10;
ll fw[N],a[N];

void update(ll idx,ll val){
    for(int i=idx;i<N;i+=(i&-i))fw[i]+=val;
}

ll query(ll idx){
    ll sum=0;
    for(int i=idx;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}

int main(){macos;

    ll t,q,c,n,m,temp;
    cin >> t >> q;
    forr(i,1,t+1){
        cin >> temp;
        a[i]=temp;
        update(i,temp);
    }
    forr(i,0,q){
        cin >> c >> n >> m;
        if(c==1){update(n,m-a[n]);a[n]=m;}
        else if(c==2)cout << query(m)-query(n-1) << endll;
    }

    return 0;
}