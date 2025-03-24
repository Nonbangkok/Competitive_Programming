#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll n,m,k,q,tmp,a,b,co,x;
vector<pair<ll,ll>> pt;
vector<ll> times,cnt;

int main(){macos;

    cin >> n >> m >> k >> q;
    forr(i,0,k){
        cin >> tmp >> a >> tmp >> b;
        pt.push_back({a,1});
        pt.push_back({b+1,-1});
    }

    sort(pt.begin(),pt.end());

    times.push_back(0);
    cnt.push_back(0);

    forr(i,0,pt.size()){
        co += pt[i].second;
        if(pt[i].first==pt[i+1].first)continue;
        times.push_back(pt[i].first);
        cnt.push_back(co);
    }

    // forr(i,0,times.size()){
    //     cout << times[i] << sp;
    // }cout << endll;
    // forr(i,0,times.size()){
    //     cout << cnt[i] << sp;
    // }cout << endll;

    while(q--){
        cin >> x;
        int idx = upper_bound(times.begin(),times.end(),x)-times.begin()-1;
        cout << cnt[idx] << endll;
    }

    return 0;
}

/*
12 6 6 6
4 1 1 5
6 3 3 4
4 3 7 6
6 1 9 2
11 2 7 4
12 1 12 6
1 2 3 4 5 6

2 2 2 2
1 1 1 2
2 1 2 2
1 2

2 2 3 2
1 1 1 2
1 1 1 2
2 2 2 2
1 2

3 3 2 2
2 2 2 3
3 2 3 3
1 2

*/