#include "../libs.hpp"


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1(nums1.size()), n2(nums2.size());
        if(n1 == 0 || n2 == 0) 
            return vector<int>();
        
        if(n1 > n2) 
            return intersection(nums2, nums1);


        unordered_map<int, bool> chk;
        vector<int> ans;
        for(auto& x: nums1)
            chk[x] = false;
        
        for(auto y: nums2)
        {
            if(chk.find(y) != chk.end() && !chk[y])
            {
                chk[y] = true;
                ans.push_back(y);
            }
        }

        return ans;
    }
};

int main()
{

    Solution S;
    return 0;
}