#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<pair<ll,ll>> sea;

int main(){macos;

    ll n,q,a,b;
    cin >> n >> q;

    forr(i,0,n){
        cin >> a >> b;
        sea.push_back({a,b});
    }
    sort(sea.begin(),sea.end());

    forr(i,0,q){
        ll l,r,sum=0;
        cin >> l >> r;

        for(auto [idx,shell]:sea){
            if(l<=idx&&idx<=r)sum+=shell;
            if(idx>r)break;
        }

        cout << sum << endll;
    }

    return 0;
}