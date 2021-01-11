#include "../libs.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] <= nums[n-1])
            return nums[0];
        
        int lo = 0, hi = n-1, m;
        while(lo < hi)
        {
            m = (lo+hi)/2;
            if(nums[m] < nums[hi])
                hi = m;
            else
                lo = m + 1;
        }
        return nums[lo];
    }
};

int main()
{
    vi nums = {3,1,2};
    Solution S;
    cout << S.findMin(nums) << endl;
    return 0;
}