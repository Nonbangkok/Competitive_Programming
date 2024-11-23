#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=4e5+10;

struct Non{
    int l,r,ix;

    bool operator < (const Non &rhs)const{
        if(r!=rhs.r)return r<rhs.r;
        return l>rhs.l;
    }
};

int seg[8*N];
vector<Non> A;
vector<int> coor;
vector<int> ans(N);

void update(int l,int r,int node,int idx,int val){
    if(idx<l||r<idx)return;
    if(l==r){seg[node]=max(seg[node],val);return;}

    int mid=(l+r)>>1;

    update(l,mid,node<<1,idx,val);
    update(mid+1,r,(node<<1)+1,idx,val);

    seg[node]=max(seg[node<<1],seg[(node<<1)+1]);
}

int query(int l,int r,int ql,int qr,int node){
    if(qr<l||r<ql)return -1;
    if(ql<=l&&r<=qr)return seg[node];

    int mid=(l+r)>>1;

    return max(query(l,mid,ql,qr,node<<1),query(mid+1,r,ql,qr,(node<<1)+1));
}

int main(){macos;

    int n,a,b;
    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        A.push_back({a,b,i});
        coor.push_back(a);
        coor.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(coor.begin(),coor.end());
    coor.erase(unique(coor.begin(),coor.end()),coor.end());

    int mx=-1;
    for(auto [l,r,idx]:A){
        l=lower_bound(coor.begin(),coor.end(),l)-coor.begin()+1;
        r=lower_bound(coor.begin(),coor.end(),r)-coor.begin()+1;
        ans[idx]=query(1,coor.size()+1,l,r,1)+1;
        update(1,coor.size()+1,1,l,ans[idx]);
        mx=max(mx,ans[idx]);
    }
    cout << mx << endll;
    forr(i,0,n)cout << ans[i] << sp;

    return 0;
}