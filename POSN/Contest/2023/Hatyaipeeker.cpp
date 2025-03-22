#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int n,t,k;
vector<pair<ll,ll>> Pts;
set<pair<ll,ll>> s;

int main(){macos;

    cin >> n >> t >> k;
    Pts.resize(n);
    forr(i,0,n)cin >> Pts[i].first >> Pts[i].second;

    sort(Pts.begin(),Pts.end());

    int j = 0;
    ll d = 1e18;
    forr(i,0,n){
        while(!s.empty() && Pts[i].first-Pts[j].first >= d)s.erase({Pts[j].second,Pts[j].first}),j++;
        auto l = s.lower_bound({Pts[i].second-d,Pts[i].first});
        auto r = s.upper_bound({Pts[i].second+d,Pts[i].first});
        for(auto it=l;it!=r;it++)d = min(d,abs(Pts[i].first-it->first)+abs(Pts[i].second-it->second));
        s.insert({Pts[i].second,Pts[i].first});
    }

    cout << d << endll;
    if(d*t>k)cout << "NO TIME = " << d*t;
    else cout << "YES TIME = " << d*t;

    return 0;
}