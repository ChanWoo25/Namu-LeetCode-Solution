#include "../libs.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            // Sorted array인 ans 안에서 
            // nums[i] 보다 크거나 같은 첫번째 원소를 찾는다.
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);

            // 만약 찾지 못했다면, it는 검사된 elem중 가장 큰 원소이므로 ans에 포함될 자격이 있다.
            // 고로 끝에 집어넣는다.
            if(it == ans.end())
                ans.push_back(nums[i]);
            // 만약 *it와 nums[i] 같다면 달라지는 것은 아무것도 없다.
            // 눈여겨 볼 것은 *it가 nums[i]보다 클 때이다.
            // 설령 nums[i]가 최종 LIS에 포함되지 않더라도 *it자리에 
            // 보다 더 작은 nums[i]가 들어있을 때, 이후 더 큰 원소를 집어넣기 유리해진다.
            // 이렇게 진행할 시, 최종 LIS는 우리가 원하는 배열이 아니겠지만, 
            // 우리가 원하는 것은 길이 뿐이므로 목적을 달성하는 것이 가능하다.
            else
                *it = nums[i];
        }

        return ans.size();
    }
};

int main()
{

    Solution S;
    return 0;
}