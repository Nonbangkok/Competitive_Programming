#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<pair<ll,ll>> pts;
ll n,m,a,b,mn;

int main(){macos;

    cin >> n >> m;
    forr(i,0,n){
        cin >> a >> b;
        pts.push_back({a,b});
    }

    forr(i,0,m){
        cin >> a >> b;
        mn = 1e18;
        forr(i,0,n)mn = min(mn,abs(a-pts[i].first)+abs(b-pts[i].second));
        cout << mn << endll;
    }

    return 0;
}