#include "../libs.hpp"


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return nums[0];

        if(nums[0] < nums[n-1])
            return nums[0];

        int lo(0), hi(n-1);
        while(lo < hi)
        {
            while(lo < hi && nums[lo] == nums[lo+1])
                lo++;
            if(lo < hi && nums[lo] > nums[lo+1])
                return nums[lo+1];
            else if(nums[lo] < nums[hi])
                return nums[lo];
            else
            {
                int m = (lo+hi)/2;
                if(nums[lo] < nums[m])
                    lo = m + 1;
                else
                    hi = m;
            }
        }

        return nums[lo];
    }
};

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mid;
        int minval = INT32_MAX;

        while(start <= end){
            mid = (start+end)/2;
            
            if(arr[start] < arr[mid])
            {
                minval = min(minval,arr[start]);
                start = mid+1;
            }
            else if(arr[mid] == arr[start]){
                minval = min(minval,arr[start]);
                start = start+1;
            }
            else{
                minval = min(arr[mid],minval);
                end = mid-1;
            }
        }
        return minval;
    }
};

int main()
{
    vi nums = {4,5,6,7,0,1,2};
    Solution S;
    cout << S.findMin(nums) << endl;
    return 0;
}
