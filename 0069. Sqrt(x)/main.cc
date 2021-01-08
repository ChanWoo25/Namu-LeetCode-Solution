#include "../libs.hpp"


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;

        // square root of INT32_MAX is 46340.xxx
        int lo(0), hi(46340), m; 

        while(lo <= hi)
        {
            m = (lo+hi)/2;
            if(x < m*m)
                hi = m - 1;
            else if(m*m < x)
                lo = m + 1;
            else
                return m;
        }
        // At last, [high + 1 = low] format and we need truncated one. So return high!
        return hi;
    }
};

int main()
{

    Solution S;
    return 0;
}