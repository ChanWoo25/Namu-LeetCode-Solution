#include "../libs.hpp"


class Solution {
private:
    vector<int> Tree;
    
    void Update(int s, int e, const int &x, int ti)
    {
        if(x < s || e < x || e < s)
            return;
        
        if(s == x && e == x){
            Tree[ti]++; 
            // cout << "Tree[" << x << "] = " << Tree[x] << endl;
            return;
        }

        int m = s + (e-s)/2;
        Update(s, m, x, 2*ti);
        Update(m+1, e, x, 2*ti+1);
        Tree[ti] = Tree[2*ti] + Tree[2*ti+1];
        // cout << "Tree[" << ti << "] = " << Tree[ti] << endl;
    }
    
    int Query(int s, int e, const int& qs, const int& qe, int ti)
    {
        if(qs <= s && e <= qe)
            return Tree[ti];
        
        if(e < qs || qe < s)
            return 0;

        int m = s + (e-s)/2;
        int ret = Query(s, m, qs, qe, 2*ti) + Query(m+1, e, qs, qe, 2*ti+1);
        // cout << "Query: s(" << s << ") e(" << e << ") qs(" << qs << ") qe(" << qe << ") ret(" << ret << ")\n";
        return ret;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        // Compute nums' size and max value & 
        // Make range [0, min(2e4, mx)] 
        int n = nums.size(), mx(0);
        for(auto& x: nums) {
            x += 1e4;
            mx = (mx >= x) ? mx : x;
        }

        // Because element's range is [0, mx]
        int height = (int)(std::ceil(log2(mx)));
        int TreeSize = 2 * (int)pow(2, height) - 1; 
        Tree.assign(TreeSize, 0);

        // Compute Answer
        vector<int> ret(n);
        ret[n-1] = 0; Update(0, mx, nums[n-1], 1);
        for(int i = n - 2; i >= 0; i--)
        {
            ret[i] = Query(0, mx, 0, nums[i]-1, 1);
            Update(0, mx, nums[i], 1);
        }
        return ret;
    }
};

int main()
{
    vi nums = {5,2,6,1};
    Solution S;
    auto ans = S.countSmaller(nums);
    print(ans);

    return 0;
}