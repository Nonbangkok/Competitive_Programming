#include "lis.h"
#include <algorithm>
#include <vector>
using namespace std;

int lis(const vector<int>& nums) {
    vector<int> Lis;
    for(int i=0;i<nums.size();i++){
        auto it = lower_bound(Lis.begin(),Lis.end(),nums[i]);
        if(it==Lis.end())Lis.push_back(nums[i]);
        else *it = nums[i];
    }
    return Lis.size();
}