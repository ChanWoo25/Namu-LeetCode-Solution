#include "../libs.hpp"


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int lo(0), hi(n-1), m;
        /**When the array was rotated, 
         * Let's refer to the first sorted array as 'F' and second as 'S'
         * If nums[m] and target belong to different array, m can be easily updated.
         * Otherwise, nums[m] and target belongs to the same array.
         * In that case, we should compare two elements again.
         */
        while(lo <= hi)
        {
            while(lo < hi && nums[lo] == nums[lo+1])
                lo++;
            while(lo < hi && nums[hi] == nums[hi-1])
                hi--;
            
            m = (lo+hi)/2;
            if(nums[m] == target) 
                return true;

            if(nums[lo] <= target)
            {
                if(nums[lo] <= nums[m]){
                    if(nums[m] < target)
                        lo = m + 1;
                    else if(target < nums[m])
                        hi = m - 1;
                }
                else
                    hi = m - 1;
            }
            else
            {
                if(nums[lo] <= nums[m])
                    lo = m + 1;
                else{
                    if(nums[m] < target)
                        lo = m + 1;
                    else if(target < nums[m])
                        hi = m - 1;
                }
            }
        }
        return false;
    }
};


class Solution1 {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int lo(0), hi(n-1), m;
        while(lo <= hi)
        {
            while(lo < hi && nums[lo] == nums[lo+1])
                lo++;
            while(lo < hi && nums[hi] == nums[hi-1])
                hi--;
            
            m = (lo+hi)/2;
            if(nums[m] == target) return true;
            
            bool midInFirst = (nums[lo] <= nums[m]);
            bool tgtInFirst = (nums[lo] <= target);
            
            if(midInFirst ^ tgtInFirst)
            {
                if(midInFirst)
                    lo = m + 1;
                else
                    hi = m - 1;
            }
            else
            {
                if(nums[m] < target)
                    lo = m + 1;
                else
                    hi = m - 1;
            }
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