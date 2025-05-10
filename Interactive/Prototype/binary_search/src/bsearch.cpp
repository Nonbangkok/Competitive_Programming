#include "bsearch.h"
#include <vector>

using namespace std;

int binary_search(const vector<int>& arr, int target) {
    int l = 0, r = arr.size(), m;
    while(l<r){
        m = (l+r) >> 1;
        if(arr[m]==target)return m;
        else if(arr[m]<target)l = m + 1;
        else r = m;
    }
    return -1;
}