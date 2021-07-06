#include "../libs.hpp"


class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long long  lo = 1, \
                            hi = (1<<30) - 1, \
                            Num = static_cast<unsigned long long>(num), \
                            m, mm;

        while(lo <= hi)
        {
            m = lo + (hi-lo)/2;
            mm = m * m;

            if(mm < Num)
                lo = m + 1;
            else if(Num < mm)
                hi = m - 1;
            else 
                return true;
        }
        
        return false;
    }
};
int main()
{

    Solution S;
    return 0;
}