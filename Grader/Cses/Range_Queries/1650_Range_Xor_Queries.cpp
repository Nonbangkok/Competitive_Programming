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
ll seg[4*N];
 
void build(int l,int r,int node){
    if(l==r){
        seg[node]=A[l];
        return;
    }
 
    int mid=(l+r)>>1;
 
    build(l,mid,node<<1);
    build(mid+1,r,(node<<1)+1);
    seg[node]=seg[node<<1]^seg[(node<<1)+1];
}
 
ll query(int l,int r,int node,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr)return seg[node];
 
    int mid=(l+r)>>1;
 
    return query(l,mid,node<<1,ql,qr)^query(mid+1,r,(node<<1)+1,ql,qr);
}
 
int main(){macos;
 
    cin >> n >> q;
    forr(i,0,n)cin >> A[i+1];
    build(1,n,1);
 
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << query(1,n,1,a,b) << endll;
    }
 
    return 0;
}