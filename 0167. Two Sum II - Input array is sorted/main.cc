#include "../libs.hpp"


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i1, t;
        for(i1 = 0; i1 < n-1; i1++)
        {
            t = target - numbers[i1];
            int l(i1+1), h(n-1), m;
            while(l <= h)
            {
                m = (l+h)/2;
                if(numbers[m] < t)
                    l = m+1;
                else if(t < numbers[m])
                    h = m-1;
                else
                    return vector<int>{i1+1, m+1};
            }
        }
        return vector<int>{'e', 'r', 'r'};
    }

    vector<int> twoSum2(vector<int>& numbers, int target) {
        int lo(0), hi(numbers.size()-1), sum;
        while((sum = numbers[lo] + numbers[hi]) != target)
        {
            if(sum < target)    lo++;
            else                hi--;
        }
        return vector<int>{++lo, ++hi};
    }
};

int main()
{

    Solution S;
    return 0;
}