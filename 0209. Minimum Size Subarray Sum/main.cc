#include "../libs.hpp"


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int n = nums.size(), sum(0);
        if(n == 0)
            return 0;

        vector<int> sums(n+1, 0);

        for(int i=1; i<=n; i++)
            sums[i] = (sum += nums[i-1]);
        
        if(sums[n] < s)
            return 0;

        int p1(0), p2;
        {
            int lo(1), hi(n);
            while(lo < hi)
            {
                int m = (lo+hi)/2;
                if(sums[m] < s)
                    lo = m+1;
                else
                    hi = m;
            }
            p2 = lo;
        }

        int minLen(p2);
        do{
            {
                int lo(p1), hi(p2), p2sum(sums[p2]);
                while(lo < hi)
                {
                    int m = (lo+hi)/2;
                    if(p2sum - sums[m] >= s)
                        lo = m + 1;
                    else
                        hi = m;
                }
                p1 = lo - 1; 
                cout << "p1 = " << p1 << endl;
            }
            minLen = (minLen < p2-p1) ? minLen : (p2-p1);
            cout << p2 << " " << p1 <<' ' << minLen << endl;
        } while(++p2 <= n);

        return minLen;
    }
};

int main()
{
    int a = 4;
    vi ns = {1,4,4};
    Solution S;
    cout << S.minSubArrayLen(a, ns) << endl;
    return 0;
}