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
    ll id,val;

    bool operator < (const Non &rhs)const{
        if(val!=rhs.val)return val<rhs.val;
        return id<rhs.id;
    }
};
vector<Non> A;

int main(){macos;

    ll n;
    cin >> n;
    ll sum = 0;

    forr(i,0,n){
        ll a,b;
        cin >> a >> b;
        A.push_back({a,b});
        sum += b;
    }
    sort(A.begin(),A.end());
    forr(i,0,n){
        cout << A[i].id << sp << A[i].val << endll;
    }
    cout << sum << endll;
    sum /= n;

    bool chk = true;
    for(int i=A.size()-1;i>=0&&A[i].val>sum;i--){
        chk = false;
        cout << A[i].id << endll;
    }
    if(chk)cout << "No Labubu";

    return 0;
}