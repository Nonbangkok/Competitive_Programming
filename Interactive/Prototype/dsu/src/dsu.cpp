#include "dsu.h"
using namespace std;

DSU::DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i) parent[i] = i;
}

int DSU::find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void DSU::unite(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr == yr) return;
    if (rank[xr] < rank[yr]) swap(xr, yr);
    parent[yr] = xr;
    if (rank[xr] == rank[yr]) ++rank[xr];
}

bool DSU::same(int x, int y) {
    return find(x) == find(y);
}