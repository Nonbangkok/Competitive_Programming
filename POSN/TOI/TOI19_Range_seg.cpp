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
    int l,r,idx;

    bool operator < (const Non &rhs)const{
        if(l!=rhs.l)return l>rhs.l;
        return r<rhs.r;
    }
};

const int N = 4e5 + 10;
int n,a,b,mx;
int ans[N];
vector<Non> mnt;
vector<int> coor;

struct Segment_tree{
    int seg[8*N];

    Segment_tree(){
        forr(i,0,8*N)seg[i] = 0;
    }

    void update(int l, int r, int node, int idx, int val){
        if(idx<l||r<idx)return;
        if(l==r){seg[node]=max(seg[node],val);return;}

        int mid = (l+r) >> 1;

        update(l,mid,node<<1,idx,val);
        update(mid+1,r,(node<<1)+1,idx,val);

        seg[node] = max(seg[node<<1],seg[(node<<1)+1]);
    }

    int query(int l, int r, int ql, int qr, int node){
        if(qr<l||r<ql)return -1;
        if(ql<=l&&r<=qr)return seg[node];

        int mid = (l+r) >> 1;

        return max(query(l,mid,ql,qr,node<<1),query(mid+1,r,ql,qr,(node<<1)+1));
    }
    
}seg;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        mnt.push_back({a,b,i});
        coor.push_back(a);coor.push_back(b);
    }

    sort(mnt.begin(),mnt.end());
    sort(coor.begin(),coor.end());
    coor.erase(unique(coor.begin(),coor.end()),coor.end());

    for(auto [l,r,i]:mnt){
        l = lower_bound(coor.begin(),coor.end(),l)-coor.begin()+1;
        r = lower_bound(coor.begin(),coor.end(),r)-coor.begin()+1;
        ans[i] = seg.query(1,coor.size()+1,l,r,1) + 1;
        seg.update(1,coor.size()+1,1,r,ans[i]);
        mx = max(mx,ans[i]);
    }

    cout << mx << endll;
    forr(i,0,n)cout << ans[i] << sp;

    return 0;
}