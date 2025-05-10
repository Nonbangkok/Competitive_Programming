#include "closest_pair.h"
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;

int manhattan_distance(const Point& a, const Point& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int closest_pair(vector<Point> points) {
    int n = points.size(), ans = 1e9;
    set<Point> s;
    sort(points.begin(),points.end());

    int j = 0;
    for(int i=0;i<n;i++){
        int d = sqrt(ans) + 1;
        while(points[i].first-points[j].first>=ans)s.erase({points[j].second,points[j].first}),j++;
        auto l = s.lower_bound({points[i].second-d,points[i].first});
        auto r = s.upper_bound({points[i].second+d,points[i].first});
        for(auto it=l;it!=r;it++)ans = min(ans,abs(points[i].first-it->second) + abs(points[i].second-it->first));
        s.insert({points[i].second,points[i].first});
    }
    
    return ans;
}
// cd closest_pair && make && ./build/main