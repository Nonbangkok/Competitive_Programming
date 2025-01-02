#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=2e5+10;
int n,q,A[N];
ll seg[4*N],lazy[4*N];

void build(int l,int r,int node){
    if(l==r){
        seg[node]=A[l];
        return;
    }

    int mid=(l+r)>>1;

    build(l,mid,node<<1);
    build(mid+1,r,(node<<1)+1);
    seg[node]=seg[node<<1]+seg[(node<<1)+1];
}

void propagate(int l,int r,int node){
    if(lazy[node]){
        seg[node] += lazy[node] * (r-l+1);
        if(l!=r){
            lazy[node>>1] = lazy[node];
            lazy[(node>>1)+1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

ll query(int l,int r,int node,int ql,int qr){
    propagate(l,r,node);

    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr)return seg[node];

    int mid=(l+r)>>1;

    return query(l,mid,node<<1,ql,qr)+query(mid+1,r,(node<<1)+1,ql,qr);
}

void range_update(int l,int r,int node,int ul,int ur,int val){
    propagate(l,r,node);

    if(ur<l||r<ul)return;
    if(l==r){
        lazy[node] = val;
        propagate(l,r,node);
        return;
    }

    int mid=(l+r)>>1;

    range_update(l,mid,node<<1,ul,ur,val);
    range_update(mid+1,r,(node<<1)+1,ul,ur,val);
    seg[node]=seg[node<<1]+seg[(node<<1)+1];
}

int main(){macos;

    cin >> n >> q;
    forr(i,0,n)cin >> A[i+1];
    build(1,n,1);

    while(q--){
        int a,b,c,d;
        cin >> a;
        if(a==1){
            cin >> b >> c >> d;
            range_update(1,n,1,b,c,d);   
        }else{
            cin >> b;
            cout << query(1,n,1,b,b) << endll;
        }
    }

    return 0;
}