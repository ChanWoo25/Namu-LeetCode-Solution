#include "../libs.hpp"


class Solution {

public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;

        int lo(0), hi(n-1), m;
        while(lo <= hi)
        {
            m = (lo+hi)>>1;
            
            if(citations[m] < n - m)
                lo = m + 1;
            else // if(citations[m] >= n - m)
                hi = m - 1;
        }

        return n - lo;
    }
};

int main()
{

    Solution S;
    return 0;
}