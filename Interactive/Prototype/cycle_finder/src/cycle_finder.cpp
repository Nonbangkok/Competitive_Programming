#include "cycle_finder.h"
using namespace std;

class DSU {
    public:
        DSU(int n) : parent(n) {
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y) {
            int xr = find(x), yr = find(y);
            if (xr == yr) return false;
            parent[yr] = xr;
            return true;
        }
    private:
        vector<int> parent;
};

bool has_cycle(int n, const vector<pair<int, int>>& edges) {
    DSU dsu(n);
    for(auto[u,v]:edges)if(!dsu.unite(u,v))return true;
    return false;
}
// cd cycle_finder && make && ./build/main