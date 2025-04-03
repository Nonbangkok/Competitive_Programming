#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n;
vector<pair<int,int>> pts;
set<pair<int,int>> s;
int ans = 1e9;

int main(){macos;

    cin >> n;
    pts.resize(n);
    for(int i = 0;i < n;i++) cin >> pts[i].first >> pts[i].second;

    sort(pts.begin(),pts.end());

    int j = 0;
    forr(i,0,n){
        int d = sqrt(ans) + 1;
        while(pts[i].first-pts[j].first>=ans)s.erase({pts[j].second,pts[j].first}),j++;
        auto it1 = s.lower_bound({pts[i].second-d,pts[i].first});
        auto it2 = s.upper_bound({pts[i].second+d,pts[i].first});
        for(auto it = it1;it != it2;it++){
            int dx = pts[i].first - it->second;
            int dy = pts[i].second - it->first;
            ans = min(ans,dx*dx+dy*dy);
        }
        s.insert({pts[i].second,pts[i].first});
        cout << pts[i].first << sp << pts[i].second << sp << d << sp << ans << endll;
    }

    cout << ans;

    return 0;
}