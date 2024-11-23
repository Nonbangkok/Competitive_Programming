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

vector<Non> mount;
vector<int> tmp(N),ans(N);

int main(){macos;

    int n,a,b;
    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        mount.push_back({a,b,i});
    }
    sort(mount.begin(),mount.end());

    int last=0;
    forr(i,0,n){
        int idx=upper_bound(tmp.begin(),tmp.begin()+last,-mount[i].l)-tmp.begin();
        if(idx==last)last++;
        tmp[idx]=-mount[i].l;
        ans[mount[i].ix]=idx+1;
    }
    cout << last << endll;
    forr(i,0,n)cout << ans[i] << sp;

    return 0;
}