#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll n,m,h,s,p,a,b,c;
bool survive[510];
vector<tuple<ll,ll,ll>> info;

int main(){macos;

    cin >> n >> m >> h >> s >> p;
    forr(i,0,m){
        cin >> a >> b >> c;
        info.push_back({b,a,c});
    }

    sort(info.begin(),info.end());

    // cout << t << sp << x << sp << h << endll;
    for(auto [t,x,h]:info){
        if(t<s)continue;
        if((t-s+1)*p<h)survive[x] = true;
    }

    cout << n - count(survive+1,survive+n+1,true) << endll;
    forr(i,1,n+1)if(!survive[i])cout << i << sp;

    return 0;
}