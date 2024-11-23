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
    ll x,y,t;
};

ll n,m,k,mn;
Non A[11];

ll time(double x1,double y1,double x2,double y2){
    return ceil(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
}

void sSearch(ll i,ll t,ll x,ll y){
    if(i==k){
        mn=min(mn,time(x,y,n-1,m-1)+t);
    }else{
        ll k=time(x,y,A[i].x,A[i].y)-A[i].t;
        sSearch(i+1,t+k,A[i].x,A[i].y);
        sSearch(i+1,t,x,y);
    }
}

int main() {macos;

    ll a,b,c;
    cin >> n >> m >> k;
    forr(i,0,k){
        cin >> a >> b >> c;
        A[i]={a,b,c};
    }
    mn=time(0,0,m-1,n-1);
    sSearch(0,0,0,0);
    cout << mn;

    return 0;
}