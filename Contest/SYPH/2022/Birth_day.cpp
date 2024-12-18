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
    int t,n,e;

    bool operator <(const Non &rhs)const{
        if(t!=rhs.t)return t<rhs.t;
        return e<rhs.e;
    }
};

int main(){macos;

    vector<Non> event;
    int q,n,a,b,c;
    cin >> q >> n;

    forr(i,0,n){
        cin >> a >> b >> c;
        event.push_back({b,a,-1});
        event.push_back({c+1,a,1});
    }
    sort(event.begin(),event.end());

    forr(i,0,q){
        cin >> a;
        int sum=0;
        for(auto [time,n,e]:event){
            if(time>a)break;
            sum-=e*n;
        }
        cout << sum << endll;
    }

    return 0;
}