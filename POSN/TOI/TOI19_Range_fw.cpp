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

struct Fenwick{
    int fw[2*N];

    Fenwick(){
        forr(i,0,2*N)fw[i] = 0;
    }

    void update(int idx, int val){
        for(int i=idx;i<=coor.size();i+=(i&-i))fw[i] = max(fw[i],val);
    }

    int query(int idx){
        int mx = 0;
        for(int i=idx;i>0;i-=(i&-i))mx = max(mx,fw[i]);
        return mx;
    }
}fw;

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
        r = lower_bound(coor.begin(),coor.end(),r)-coor.begin()+1;
        ans[i] = fw.query(r) + 1;
        fw.update(r,ans[i]);
        mx = max(mx,ans[i]);
    }

    cout << mx << endll;
    forr(i,0,n)cout << ans[i] << sp;

    return 0;
}