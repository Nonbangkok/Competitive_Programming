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
    string str;
    int type;

    bool operator < (const Non &rhs)const{
        return str<rhs.str;
    }
};

vector<Non> A;

int main(){macos;

    string a,b;
    int n;
    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        A.push_back({a,1});
        A.push_back({b,-1});
    }
    sort(A.begin(),A.end());

    int cnt=0,mx=0;
    for(auto i:A)cnt+=i.type,mx=max(mx,cnt);
    cout << mx;

    return 0;
}