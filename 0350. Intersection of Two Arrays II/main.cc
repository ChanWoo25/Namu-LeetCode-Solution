#include "../libs.hpp"


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int _i1(0), _i2(0), x, y;
        vector<int> ans;
        while(_i1 < nums1.size() && _i2 < nums2.size())
        {
            x = nums1[_i1], y = nums2[_i2];
            if(x == y)
                ans.push_back(x), _i1++, _i2++;
            else if(x < y)
                _i1++;
            else // if(y < x)
                _i2++;
        }
        
        return ans;
    }
};

int main()
{
    vi nums1 = {1,2,2,1}, nums2 = {2,2};
    Solution S;
    auto ans = S.intersect(nums1, nums2);

    for(auto x : ans)
        cout << x << endl;
    return 0;
}