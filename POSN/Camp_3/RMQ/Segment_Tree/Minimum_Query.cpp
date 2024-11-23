#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
// Cses 1647
const int N=2e5+10;
int n,q,A[N],seg[4*N];

void build(int l,int r,int node){
    if(l==r){
        seg[node]=A[l];
        return;
    }

    int mid=(l+r)>>1;

    build(l,mid,(node<<1));
    build(mid+1,r,(node<<1)+1);
    seg[node]=min(seg[node<<1],seg[(node<<1)+1]);
}

int query(int l,int r,int node,int ql,int qr){
    if(qr<l||r<ql)return INT_MAX;
    if(ql<=l&&r<=qr)return seg[node];

    int mid=(l+r)>>1;

    return min(query(l,mid,node<<1,ql,qr),query(mid+1,r,(node<<1)+1,ql,qr));
}

int main(){macos;

    cin >> n >> q;
    forr(i,1,n+1)cin >> A[i];
    build(1,N,1);
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << query(1,N,1,l,r) << endll;
    }

    return 0;
}