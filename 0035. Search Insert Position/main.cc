#include "../libs.hpp"


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        int idx = it - nums.begin();
        
        if(it == nums.end())
            return nums.size();
        else
            return idx;
    }
};
int main()
{

    Solution S;
    return 0;
}