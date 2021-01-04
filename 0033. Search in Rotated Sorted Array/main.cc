#include "../libs.hpp"

/** 이전에 알던 Bisection Method는 한 쪽은 낮고, 한쪽은 높은 불변식을 가정하였기에
 * 가능한 문제 풀이었다.
 * 이 문제는 배열이 Rotate된 형태를 고려해주어야 한다.
 * 1. ascending array를 돌려놓은 것이기 때문에 값의 대소가 나뉘는 부분을 먼저 찾으면? -> O(N)이라 BS의 의미가 퇴색.
 * 2. 처음엔 행렬의 pivot을 찾기 위해 BS를 수행한다.
 *  - 그리고 pivot을 찾으면 양 옆을 lo, hi로 잡고 BS를 수행한다.
 *  - 예외적인 케이스는 로테이트가 되지 않고, 처음부터 배열이 완벽하게 정렬되어 있는 경우임. 
 *      -> nums[lo] > nums[hi] 를 조건으로 줌으로써 애초에 검사하지 않게 함.
 *  - 그 후 lo가 무조건 낮은 숫자를 가지고 있게 한 뒤, 두 번째 BS에서 실제 Array에 접근하기 위한 Offset을 lo로 저장함.
 */ 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Find pivot.
        int n = nums.size();
        int lo=0, hi=n-1, mid;
        while(lo<hi && nums[lo] > nums[hi])
        {
            mid = (lo+hi)/2;
            if(nums[lo] < nums[mid])
                lo = mid;
            else if(nums[mid] < nums[hi])
                hi = mid;
            
            if(lo+1 == hi)
                break;
        }

        // lo = highest, hi = lowest
        if(nums[lo] > nums[hi])
            swap(lo, hi); // -> nums[lo] < nums[hi]
        cout << "Lowest: " << lo << endl;
        // find target
        int rot = lo, _mid;
        lo = 0, hi = n-1, mid=0;
        while(1)
        {
            mid = (lo+hi)/2;
            _mid = (mid+rot)%n;
            if(lo >= hi) break;

            if(target < nums[_mid])
                hi = mid-1;
            else if(nums[_mid] < target)
                lo = mid+1;
            else
                return _mid;
        }

        if(target == nums[_mid])
            return _mid;
        else
            return -1;
    }
};

int main()
{

    Solution S;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << S.search(nums, target) << endl;

    return 0;
}