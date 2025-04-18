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
vector<int> lis;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        mnt.push_back({a,b,i});
    }

    sort(mnt.begin(),mnt.end());

    for(auto [l,r,i]:mnt){
        auto it = upper_bound(lis.begin(),lis.end(),r);
        ans[i] = (it-lis.begin()) + 1;
        if(it==lis.end())lis.push_back(r);
        else *it = r;
        mx = max(mx,ans[i]);
    }
    
    cout << mx << endll;
    forr(i,0,n)cout << ans[i] << sp;

    return 0;
}