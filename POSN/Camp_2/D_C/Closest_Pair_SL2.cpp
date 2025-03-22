#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > pts;
set<pair<int,int> > s;
long long d = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    pts.resize(n);
    for(int i = 0;i < n;i++) cin >> pts[i].first >> pts[i].second;
    sort(pts.begin(),pts.end());

    int j = 0;
    for(int i = 0;i < n;i++){
        while(!s.empty() && pts[i].first - pts[j].first >= d){
            s.erase({pts[j].second,pts[j].first});
            j++;
        }
        auto it1 = s.lower_bound({pts[i].second-d,pts[i].first});
        auto it2 = s.upper_bound({pts[i].second+d,pts[i].first});
        for(auto it = it1;it != it2;it++){
            int dx = pts[i].first - it->second;
            int dy = pts[i].second - it->first;
            d = min(d,1LL*dx*dx + 1LL*dy*dy);
        }
        s.insert({pts[i].second,pts[i].first});
    }

    cout << d;
}