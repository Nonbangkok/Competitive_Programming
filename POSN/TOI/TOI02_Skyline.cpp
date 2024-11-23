#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int pos,type,high;

    bool operator < (const Non &rhs)const{
        if(pos!=rhs.pos) return pos<rhs.pos;
        if(type!=rhs.type) return type<rhs.type;
        if(type==1) return high>rhs.high;
        else return high<rhs.high;
    }
};

int main() {macos;

    vector<Non> A;
    int n;
    cin >> n;
    forr(i,0,n){
        int l,h,r;
        cin >> l >> h >> r;
        A.push_back({l,1,h});
        A.push_back({r,2,h});
    }
    sort(A.begin(),A.end());

    multiset<int> H;
    H.insert(0);
    int mx=0;
    for(auto i : A){
        if(i.type==1) H.insert(i.high);
        else H.erase(H.find(i.high));

        int mxset = *H.rbegin();
        if(mx!=mxset){
            cout << i.pos << sp << mxset << sp;
            mx = mxset;
        }
    }

    return 0;
}