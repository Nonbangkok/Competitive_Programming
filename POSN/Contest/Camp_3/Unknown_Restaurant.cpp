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
int n,q,cmd,k,x;
int a[N];

struct seg{
    int seg[4*N];

    void build(int l, int r, int node, int sign){
        if(l==r){
            seg[node] = a[l] + sign * l;
            return;
        }

        int mid = (l+r) >> 1;
        build(l,mid,node<<1,sign);
        build(mid+1,r,(node<<1)+1,sign);

        seg[node] = min(seg[node<<1],seg[(node<<1)+1]);
    }

    void update(int l, int r, int node, int idx, int val){
        if(idx<l||r<idx)return;
        if(l==r){
            seg[node] = val;
            return;
        }

        int mid = (l+r) >> 1;
        update(l,mid,node<<1,idx,val);
        update(mid+1,r,(node<<1)+1,idx,val);

        seg[node] = min(seg[node<<1],seg[(node<<1)+1]);
    }

    int query(int l, int r, int node, int ql, int qr){
        if(qr<l||r<ql)return INT_MAX;
        if(ql<=l&&r<=qr)return seg[node];

        int mid = (l+r) >> 1;

        return min(query(l,mid,node<<1,ql,qr),query(mid+1,r,(node<<1)+1,ql,qr));
    }
}seg1,seg2;

int main(){macos;

    cin >> n >> q;
    forr(i,1,n+1)cin >> a[i];
    seg1.build(1,n,1,-1);
    seg2.build(1,n,1,1);
    while(q--){
        cin >> cmd;
        if(cmd==1){
            cin >> k >> x;
            seg1.update(1,n,1,k,x-k);
            seg2.update(1,n,1,k,x+k);
        }else{
            cin >> k;
            cout << min(seg1.query(1,n,1,1,k)+k,seg2.query(1,n,1,k+1,n)-k) << endll;
        }
    }

    return 0;
}