#include "../libs.hpp"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;

        int lo(0), hi(n-1), m;
        while (lo < hi)
        {
            m = (lo+hi)/2;
            if(m > 0 && nums[m-1] > nums[m])
                hi = m - 1;
            else if(m < (n-1) && nums[m] < nums[m+1])
                lo = m + 1;
            else
                return m; // Peak found
        }
        return lo;
    }
};

int main()
{

    Solution S;
    return 0;
}