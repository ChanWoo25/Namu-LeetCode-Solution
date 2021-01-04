#include "libs.hpp"

class Solution {
public:
    int MAX = 0x7FFFFFFF;
    int MIN = 0x80000000;

    int divide(int dividend, int divisor) 
    {
        if(dividend == 0)   
            return 0;
        if(divisor == 1)
            return dividend;
        if(dividend == MIN)
        {
            if(divisor == -1)
                return MAX;
            else
            {
                if(divisor > 0)
                    return -1 + divide(dividend+divisor, divisor);
                else // divisor < 0
                    return 1 + divide(dividend-divisor, divisor);
            }   
        }
        if(divisor == MIN)
            return 0;
            
        int neg = (dividend<0) ^ (divisor<0);
        int dvd = abs(dividend), dvs = abs(divisor);
        cout << dvd << ' ' << dvs << endl;
        int res = 0;

        while(dvd >= dvs)
        {
            int tmp(dvs), m(1);
            while(tmp < (1<<30) && (tmp<<1) <= dvd)
                tmp <<= 1, m <<= 1;
            
            dvd -= tmp;
            res += m;
        }

        if(neg) return (~res+1);
        else    return res;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {1,2,2,2,5,0};
    int c = (1<<31);
    cout << c << endl;
    cout << (c>>1) << endl;
    cout << S.divide(INT32_MIN, 2) << endl;
    return 0;
}