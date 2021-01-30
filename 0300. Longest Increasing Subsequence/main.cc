#include "../libs.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans(1);
        vector<int> DP(n, 0);
        
        DP[0] = 1;
        for(int i=1; i<n; i++)
        {
            int maxLen(0);
            for(int j=0; j<i; j++)
            {
                if(nums[j] < nums[i])
                    maxLen = (maxLen>DP[j])?maxLen:DP[j];
            }
            DP[i] = maxLen + 1;
            ans = (ans>DP[i])?ans:DP[i];
        }
        return ans;
    }
};

int main()
{

    Solution S;
    return 0;
}