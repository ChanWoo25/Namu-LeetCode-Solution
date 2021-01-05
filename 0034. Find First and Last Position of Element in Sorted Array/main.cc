#include "../libs.hpp"


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it == nums.end() || *it != target)
            return vector<int>({-1, -1});
        
        int start = it - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return vector<int>({start, end});
    }

    /** break 포인트가 없고, 조건문이 low<=high이므로 
     * t를 찾아도 계속 수행 && low==t, high!=t일 때 멈춤. */
    int findLow(vi& nums, int t, int low, int high)
    {
        int mid;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(nums[mid] == t)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }

    /** break 포인트가 없고, 조건문이 low<=high이므로 
     * t를 찾아도 계속 수행 && low!=t, high==t일 때 멈춤. */
    int findHigh(vi& nums, int t, int low, int high)
    {   
        int mid;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(nums[mid]==t)
                low = mid+1;
            else 
                high = mid-1;
        }
        return high;
    }

    // 내가 쓴 방법은 첫 점과 끝점을 각각 찾아서 O(2*lgN)에 수행하는 알고리즘.
    // 이 방법은 target에 해당하는 mid를 찾은 순간 [low, high] 안에서 범위를 새로 찾는 방법
    // Worst = [한번에 target을 찾은 경우] 1 + 2*(O(lgN)-1)
    vector<int> searchRange2(vector<int> &nums, int target)
    {
        int size = nums.size(), low = 0, high = size - 1, mid;
        vector<int> pos(2, -1);

        while (low <= high) {
            mid = low + (high - low) / 2;
			
			//First check if the target is present in the list at all
            if (nums[mid] == target)
            {
                if (nums[low] != target)
					//Low should be in the lower half
                    low = findLow(nums, target, low, mid);
                
                if (nums[high] != target) 
					//High should be in the upper half
                    high = findHigh(nums, target, mid, high);
                
                pos[0] = low;
                pos[1] = high;
                break;
            }
            else if (nums[mid] > target && nums[high] != target)
                high = mid - 1;
            else if (nums[mid] < target && nums[low] != target)
                low = mid + 1;
        }
        return pos;
    }

};

int main()
{

    Solution S;
    vi nums = {5,7,7,8,8,10};
    int target = 6;

    auto v = S.searchRange(nums, target);
    cout << v[0] << ", " << v[1] << endl;

    return 0;
}