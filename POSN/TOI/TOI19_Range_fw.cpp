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
        if(l!=rhs.l)return l>rhs.l;
        return r<rhs.r;
    }
};

int fw[2*N];
vector<Non> A;
vector<int> coor,ans(N);

void update(int idx,int val){
    for(int i=idx;i<=coor.size();i+=(i&-i))fw[i]=max(fw[i],val);
}

int query(int idx){
    int tmp=0;
    for(int i=idx;i>0;i-=(i&-i))tmp=max(tmp,fw[i]);
    return tmp;
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
        r=lower_bound(coor.begin(),coor.end(),r)-coor.begin()+1;
        ans[idx]=query(r)+1;
        update(r,ans[idx]);
        mx=max(mx,ans[idx]);
    }
    cout << mx << endll;
    forr(i,0,n)cout << ans[i] << sp;

    return 0;
}