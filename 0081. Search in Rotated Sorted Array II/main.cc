#include "../libs.hpp"


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int lo, hi, m, pivot;
        if(nums[0] >= nums[n-1]) 
        {   // pivot exists. Find It!
            lo = 0, hi = n-1;
            while(lo < hi)
            {
                m = (lo+hi)/2;
                if(nums[m] <= nums[hi])
                    hi = m;
                else if(nums[lo] <= nums[m])
                    lo = m + 1;
            }
            pivot = lo;
        }
        // cout << pivot << endl;

        lo = 0, hi = n - 1;
        while(lo <= hi)
        {
            m = (lo+hi)/2;
            int rot_m = (m + pivot) % n;

            if(nums[rot_m] < target)
                lo = m + 1;
            else if(target < nums[rot_m])
                hi = m - 1;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    vi nums = {2,5,6,0,0,1,2};
    int target = 0;

    Solution S;
    cout << S.search(nums, target) << endl;
    return 0;
}