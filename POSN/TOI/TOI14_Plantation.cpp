#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

bool sol(){
    ll n,r,d,a,b,dis;
    vector<pair<ll,ll>> A;
    cin >> n >> r >> d;
    dis=r+r+d;
    forr(i,0,n)cin >> a >> b,A.push_back({a,b});
    sort(A.begin(),A.end());
    forr(i,0,n-1)forr(j,i+1,n){
        ll x=A[j].first-A[i].first;
        ll y=A[j].second-A[i].second;
        if(x>dis||y>dis)break;
        if(x*x+y*y>=dis*dis)continue;
        return false;
    }   
    return true;
}

int main(){macos;

    ll t;
    cin >> t;
    while(t--)cout << (sol()?'Y':'N') << endll;

    return 0;
}