#ifndef DSU_H
#define DSU_H

#include <vector>

class DSU {
public:
    DSU(int n);
    int find(int x);
    void unite(int x, int y);
    bool same(int x, int y);

private:
    std::vector<int> parent, rank;
};

#endif // DSU_H