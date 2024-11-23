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
    int l,r,s;

    bool operator <(const Non &rhs)const{
        if(l!=rhs.l)return l<rhs.l;
        if(s!=rhs.s)return s>rhs.s;
        return r<rhs.r;
    }
};

int mn=1e9;
vector<Non> A;

void solve(int score,int day,int idx,int prev){
    if(score>=100)mn=min(mn,day);
    else{
        forr(i,idx,A.size()){
            if(prev>=A[i].l)continue;
            solve(score+A[i].s,day+A[i].r-A[i].l+1,i+1,A[i].r);
        }
    }
}

int main() {macos;

    int k,n,a,b,c;
    cin >> k >> n;

    forr(i,0,n){
        cin >> a >> b >> c;
        A.push_back({a,b,c});
    }
    sort(A.begin(),A.end());

    solve(k,0,0,-1);
    cout << (mn==1e9?-1:mn);

    return 0;
}